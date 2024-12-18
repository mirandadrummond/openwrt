/*
 *  Atheros AR71xx/AR724x/AR913x specific interrupt handling
 *
 *  Copyright (C) 2018 John Crispin <john@phrozen.org>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#include <linux/interrupt.h>
#include <linux/irqchip.h>
#include <linux/of.h>
#include <linux/of_irq.h>
#include <linux/irqdomain.h>

#include <asm/irq_cpu.h>
#include <asm/mach-ath79/ath79.h>
#include <asm/mach-ath79/ar71xx_regs.h>

#define ATH79_MAX_INTC_CASCADE	3

struct ath79_intc {
	struct irq_chip chip;
	u32 irq;
	u32 pending_mask;
	u32 int_status;
	u32 irq_mask[ATH79_MAX_INTC_CASCADE];
	u32 irq_wb_chan[ATH79_MAX_INTC_CASCADE];
};

static void ath79_intc_irq_handler(struct irq_desc *desc)
{
	struct irq_domain *domain = irq_desc_get_handler_data(desc);
	struct ath79_intc *intc = domain->host_data;
	u32 pending;

	pending = ath79_reset_rr(intc->int_status);
	pending &= intc->pending_mask;

	if (pending) {
		int i;

		for (i = 0; i < domain->hwirq_max; i++)
			if (pending & intc->irq_mask[i]) {
				if (intc->irq_wb_chan[i] != 0xffffffff)
					ath79_ddr_wb_flush(intc->irq_wb_chan[i]);
				generic_handle_irq(irq_find_mapping(domain, i));
			}
	} else {
		spurious_interrupt();
	}
}

static void ath79_intc_irq_enable(struct irq_data *d)
{
	struct ath79_intc *intc = d->domain->host_data;
	enable_irq(intc->irq);
}

static void ath79_intc_irq_disable(struct irq_data *d)
{
	struct ath79_intc *intc = d->domain->host_data;
	disable_irq(intc->irq);
}

static int ath79_intc_map(struct irq_domain *d, unsigned int irq, irq_hw_number_t hw)
{
	struct ath79_intc *intc = d->host_data;

	irq_set_chip_and_handler(irq, &intc->chip, handle_level_irq);

	return 0;
}

static const struct irq_domain_ops ath79_irq_domain_ops = {
	.xlate = irq_domain_xlate_onecell,
	.map = ath79_intc_map,
};

static int __init ath79_intc_of_init(
	struct device_node *node, struct device_node *parent)
{
	struct irq_domain *domain;
	struct ath79_intc *intc;
	int cnt, cntwb, i, err;

	cnt = of_property_count_u32_elems(node, "qca,pending-bits");
	if (cnt > ATH79_MAX_INTC_CASCADE)
		panic("Too many INTC pending bits\n");

	intc = kzalloc(sizeof(*intc), GFP_KERNEL);
	if (!intc)
		panic("Failed to allocate INTC memory\n");
	intc->chip = dummy_irq_chip;
	intc->chip.name = "INTC";
	intc->chip.irq_disable = ath79_intc_irq_disable;
	intc->chip.irq_enable = ath79_intc_irq_enable;

	if (of_property_read_u32(node, "qca,int-status-addr", &intc->int_status) < 0) {
		panic("Missing address of interrupt status register\n");
	}

	of_property_read_u32_array(node, "qca,pending-bits", intc->irq_mask, cnt);
	for (i = 0; i < cnt; i++) {
		intc->pending_mask |= intc->irq_mask[i];
		intc->irq_wb_chan[i] = 0xffffffff;
	}

	cntwb = of_count_phandle_with_args(
		node, "qca,ddr-wb-channels", "#qca,ddr-wb-channel-cells");

	for (i = 0; i < cntwb; i++) {
		struct of_phandle_args args;
		u32 irq = i;

		of_property_read_u32_index(
			node, "qca,ddr-wb-channel-interrupts", i, &irq);
		if (irq >= ATH79_MAX_INTC_CASCADE)
			continue;

		err = of_parse_phandle_with_args(
			node, "qca,ddr-wb-channels",
			"#qca,ddr-wb-channel-cells",
			i, &args);
		if (err)
			return err;

		intc->irq_wb_chan[irq] = args.args[0];
	}

	intc->irq = irq_of_parse_and_map(node, 0);
	if (!intc->irq)
		panic("Failed to get INTC IRQ");

	domain = irq_domain_add_linear(node, cnt, &ath79_irq_domain_ops, intc);
	irq_set_chained_handler_and_data(intc->irq, ath79_intc_irq_handler, domain);

	return 0;
}
IRQCHIP_DECLARE(ath79_intc, "qca,ar9340-intc",
		ath79_intc_of_init);
