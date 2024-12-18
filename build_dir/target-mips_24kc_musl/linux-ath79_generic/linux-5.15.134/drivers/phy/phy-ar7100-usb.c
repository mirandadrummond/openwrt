/*
 * Copyright (C) 2018 John Crispin <john@phrozen.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/phy/phy.h>
#include <linux/delay.h>
#include <linux/reset.h>
#include <linux/of_gpio.h>

#include <asm/mach-ath79/ath79.h>
#include <asm/mach-ath79/ar71xx_regs.h>

struct ar7100_usb_phy {
	struct reset_control	*rst_phy;
	struct reset_control	*rst_host;
	struct reset_control	*rst_ohci_dll;
	void __iomem		*io_base;
	struct phy		*phy;
	int			gpio;
};

static int ar7100_usb_phy_power_off(struct phy *phy)
{
	struct ar7100_usb_phy *priv = phy_get_drvdata(phy);
	int err = 0;

	err |= reset_control_assert(priv->rst_host);
	err |= reset_control_assert(priv->rst_phy);
	err |= reset_control_assert(priv->rst_ohci_dll);

	return err;
}

static int ar7100_usb_phy_power_on(struct phy *phy)
{
	struct ar7100_usb_phy *priv = phy_get_drvdata(phy);
	int err = 0;

	err |= ar7100_usb_phy_power_off(phy);
	mdelay(100);
	err |= reset_control_deassert(priv->rst_ohci_dll);
	err |= reset_control_deassert(priv->rst_phy);
	err |= reset_control_deassert(priv->rst_host);
	mdelay(500);
	iowrite32(0xf0000, priv->io_base + AR71XX_USB_CTRL_REG_CONFIG);
	iowrite32(0x20c00, priv->io_base + AR71XX_USB_CTRL_REG_FLADJ);

	return err;
}

static const struct phy_ops ar7100_usb_phy_ops = {
	.power_on	= ar7100_usb_phy_power_on,
	.power_off	= ar7100_usb_phy_power_off,
	.owner		= THIS_MODULE,
};

static int ar7100_usb_phy_probe(struct platform_device *pdev)
{
	struct phy_provider *phy_provider;
	struct resource *res;
	struct ar7100_usb_phy *priv;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	priv->io_base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(priv->io_base))
		return PTR_ERR(priv->io_base);

	priv->rst_phy = devm_reset_control_get(&pdev->dev, "usb-phy");
	if (IS_ERR(priv->rst_phy)) {
		dev_err(&pdev->dev, "phy reset is missing\n");
		return PTR_ERR(priv->rst_phy);
	}

	priv->rst_host = devm_reset_control_get(&pdev->dev, "usb-host");
	if (IS_ERR(priv->rst_host)) {
		dev_err(&pdev->dev, "host reset is missing\n");
		return PTR_ERR(priv->rst_host);
	}

	priv->rst_ohci_dll = devm_reset_control_get(&pdev->dev, "usb-ohci-dll");
	if (IS_ERR(priv->rst_ohci_dll)) {
		dev_err(&pdev->dev, "ohci-dll reset is missing\n");
		return PTR_ERR(priv->rst_host);
	}

	priv->phy = devm_phy_create(&pdev->dev, NULL, &ar7100_usb_phy_ops);
	if (IS_ERR(priv->phy)) {
		dev_err(&pdev->dev, "failed to create PHY\n");
		return PTR_ERR(priv->phy);
	}

	priv->gpio = of_get_gpio(pdev->dev.of_node, 0);
	if (priv->gpio >= 0) {
		int ret = devm_gpio_request(&pdev->dev, priv->gpio, dev_name(&pdev->dev));

		if (ret) {
			dev_err(&pdev->dev, "failed to request gpio\n");
			return ret;
		}
		gpio_export_with_name(priv->gpio, 0, dev_name(&pdev->dev));
		gpio_set_value(priv->gpio, 1);
	}

	phy_set_drvdata(priv->phy, priv);

	phy_provider = devm_of_phy_provider_register(&pdev->dev, of_phy_simple_xlate);


	return PTR_ERR_OR_ZERO(phy_provider);
}

static const struct of_device_id ar7100_usb_phy_of_match[] = {
	{ .compatible = "qca,ar7100-usb-phy" },
	{}
};
MODULE_DEVICE_TABLE(of, ar7100_usb_phy_of_match);

static struct platform_driver ar7100_usb_phy_driver = {
	.probe	= ar7100_usb_phy_probe,
	.driver = {
		.of_match_table	= ar7100_usb_phy_of_match,
		.name		= "ar7100-usb-phy",
	}
};
module_platform_driver(ar7100_usb_phy_driver);

MODULE_DESCRIPTION("ATH79 USB PHY driver");
MODULE_AUTHOR("Alban Bedel <albeu@free.fr>");
MODULE_LICENSE("GPL");
