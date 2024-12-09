cmd_/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/linux-ath79_generic/gpio-button-hotplug/gpio-button-hotplug.mod.o := mips-openwrt-linux-musl-gcc -Wp,-MMD,/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/linux-ath79_generic/gpio-button-hotplug/.gpio-button-hotplug.mod.o.d -nostdinc -isystem /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/lib/gcc/mips-openwrt-linux-musl/12.3.0/include -I./arch/mips/include -I./arch/mips/include/generated -I./include -I./arch/mips/include/uapi -I./arch/mips/include/generated/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/compiler-version.h -include ./include/linux/kconfig.h -include ./include/linux/compiler_types.h -D__KERNEL__ -DVMLINUX_LOAD_ADDRESS=0xffffffff80060000 -DLINKER_LOAD_ADDRESS=0x80060000 -DDATAOFFSET=0 -fmacro-prefix-map=./= -Wall -Wundef -Werror=strict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -fno-PIE -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Wno-format-security -std=gnu11 -mno-check-zero-division -mabi=32 -G 0 -mno-abicalls -fno-pic -pipe -mno-branch-likely -msoft-float -DGAS_HAS_SET_HARDFLOAT -Wa,-msoft-float -ffreestanding -EB -fno-stack-check -Wa,-mno-fix-loongson3-llsc -march=mips32r2 -mtune=34kc -Wa,--trap -DTOOLCHAIN_SUPPORTS_VIRT -DTOOLCHAIN_SUPPORTS_XPA -DTOOLCHAIN_SUPPORTS_CRC -DTOOLCHAIN_SUPPORTS_DSP -DTOOLCHAIN_SUPPORTS_GINV -I./arch/mips/include/asm/mach-ath79 -I./arch/mips/include/asm/mach-generic -fno-asynchronous-unwind-tables -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-address-of-packed-member -O2 -fno-allow-store-data-races -Wframe-larger-than=1024 -fstack-protector -Werror -Wimplicit-fallthrough=5 -Wno-main -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-dangling-pointer -fomit-frame-pointer -fno-stack-clash-protection -g -fno-var-tracking -femit-struct-debug-baseonly -Wdeclaration-after-statement -Wvla -Wno-pointer-sign -Wno-stringop-truncation -Wno-zero-length-bounds -Wno-array-bounds -Wno-stringop-overflow -Wno-restrict -Wno-maybe-uninitialized -Wno-alloc-size-larger-than -fno-strict-overflow -fno-stack-check -fconserve-stack -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -Wno-packed-not-aligned -fmacro-prefix-map=/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl=target-mips_24kc_musl -fno-caller-saves -DMODULE -mno-long-calls -DKBUILD_BASENAME='"gpio_button_hotplug.mod"' -DKBUILD_MODNAME='"gpio_button_hotplug"' -D__KBUILD_MODNAME=kmod_gpio_button_hotplug -c -o /mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/linux-ath79_generic/gpio-button-hotplug/gpio-button-hotplug.mod.o /mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/linux-ath79_generic/gpio-button-hotplug/gpio-button-hotplug.mod.c

source_/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/linux-ath79_generic/gpio-button-hotplug/gpio-button-hotplug.mod.o := /mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/linux-ath79_generic/gpio-button-hotplug/gpio-button-hotplug.mod.c

deps_/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/linux-ath79_generic/gpio-button-hotplug/gpio-button-hotplug.mod.o := \
    $(wildcard include/config/MODULE_UNLOAD) \
    $(wildcard include/config/RETPOLINE) \
  include/linux/compiler-version.h \
    $(wildcard include/config/CC_VERSION_TEXT) \
  include/linux/kconfig.h \
    $(wildcard include/config/CPU_BIG_ENDIAN) \
    $(wildcard include/config/BOOGER) \
    $(wildcard include/config/FOO) \
  include/linux/compiler_types.h \
    $(wildcard include/config/HAVE_ARCH_COMPILER_H) \
    $(wildcard include/config/CC_HAS_ASM_INLINE) \
  include/linux/compiler_attributes.h \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/ARCH_USE_BUILTIN_BSWAP) \
    $(wildcard include/config/KCOV) \
  arch/mips/include/asm/compiler.h \
    $(wildcard include/config/CPU_MIPSR6) \
    $(wildcard include/config/CPU_MIPSR5) \
  include/linux/module.h \
    $(wildcard include/config/MODULES) \
    $(wildcard include/config/MODULE_STRIPPED) \
    $(wildcard include/config/SYSFS) \
    $(wildcard include/config/MODULES_TREE_LOOKUP) \
    $(wildcard include/config/LIVEPATCH) \
    $(wildcard include/config/STACKTRACE_BUILD_ID) \
    $(wildcard include/config/CFI_CLANG) \
    $(wildcard include/config/MODULE_SIG) \
    $(wildcard include/config/GENERIC_BUG) \
    $(wildcard include/config/KALLSYMS) \
    $(wildcard include/config/SMP) \
    $(wildcard include/config/TRACEPOINTS) \
    $(wildcard include/config/TREE_SRCU) \
    $(wildcard include/config/BPF_EVENTS) \
    $(wildcard include/config/DEBUG_INFO_BTF_MODULES) \
    $(wildcard include/config/JUMP_LABEL) \
    $(wildcard include/config/TRACING) \
    $(wildcard include/config/EVENT_TRACING) \
    $(wildcard include/config/FTRACE_MCOUNT_RECORD) \
    $(wildcard include/config/KPROBES) \
    $(wildcard include/config/HAVE_STATIC_CALL_INLINE) \
    $(wildcard include/config/PRINTK_INDEX) \
    $(wildcard include/config/CONSTRUCTORS) \
    $(wildcard include/config/FUNCTION_ERROR_INJECTION) \
  include/linux/list.h \
    $(wildcard include/config/DEBUG_LIST) \
  include/linux/types.h \
    $(wildcard include/config/HAVE_UID16) \
    $(wildcard include/config/UID16) \
    $(wildcard include/config/ARCH_DMA_ADDR_T_64BIT) \
    $(wildcard include/config/PHYS_ADDR_T_64BIT) \
    $(wildcard include/config/64BIT) \
    $(wildcard include/config/ARCH_32BIT_USTAT_F_TINODE) \
  include/uapi/linux/types.h \
  arch/mips/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  include/uapi/asm-generic/int-ll64.h \
  arch/mips/include/uapi/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/uapi/asm-generic/bitsperlong.h \
  include/uapi/linux/posix_types.h \
  include/linux/stddef.h \
  include/uapi/linux/stddef.h \
  include/linux/compiler_types.h \
  arch/mips/include/uapi/asm/posix_types.h \
  arch/mips/include/uapi/asm/sgidefs.h \
  include/uapi/asm-generic/posix_types.h \
  include/linux/poison.h \
    $(wildcard include/config/ILLEGAL_POINTER_VALUE) \
  include/linux/const.h \
  include/vdso/const.h \
  include/uapi/linux/const.h \
  include/linux/kernel.h \
    $(wildcard include/config/PREEMPT_VOLUNTARY) \
    $(wildcard include/config/PREEMPT_DYNAMIC) \
    $(wildcard include/config/PREEMPT_) \
    $(wildcard include/config/DEBUG_ATOMIC_SLEEP) \
    $(wildcard include/config/MMU) \
    $(wildcard include/config/PROVE_LOCKING) \
  include/linux/stdarg.h \
  include/linux/align.h \
  include/linux/limits.h \
  include/uapi/linux/limits.h \
  include/vdso/limits.h \
  include/linux/linkage.h \
    $(wildcard include/config/ARCH_USE_SYM_ANNOTATIONS) \
  include/linux/stringify.h \
  include/linux/export.h \
    $(wildcard include/config/MODVERSIONS) \
    $(wildcard include/config/MODULE_REL_CRCS) \
    $(wildcard include/config/HAVE_ARCH_PREL32_RELOCATIONS) \
    $(wildcard include/config/TRIM_UNUSED_KSYMS) \
  arch/mips/include/asm/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/TRACE_BRANCH_PROFILING) \
    $(wildcard include/config/PROFILE_ALL_BRANCHES) \
    $(wildcard include/config/STACK_VALIDATION) \
  arch/mips/include/generated/asm/rwonce.h \
  include/asm-generic/rwonce.h \
  include/linux/kasan-checks.h \
    $(wildcard include/config/KASAN_GENERIC) \
    $(wildcard include/config/KASAN_SW_TAGS) \
  include/linux/kcsan-checks.h \
    $(wildcard include/config/KCSAN) \
    $(wildcard include/config/KCSAN_IGNORE_ATOMICS) \
  include/linux/bitops.h \
  include/linux/bits.h \
  include/vdso/bits.h \
  include/linux/build_bug.h \
  include/linux/typecheck.h \
  include/uapi/linux/kernel.h \
  include/uapi/linux/sysinfo.h \
  arch/mips/include/asm/bitops.h \
  arch/mips/include/asm/barrier.h \
    $(wildcard include/config/CPU_CAVIUM_OCTEON) \
    $(wildcard include/config/SGI_IP28) \
    $(wildcard include/config/CPU_HAS_WB) \
    $(wildcard include/config/WEAK_ORDERING) \
    $(wildcard include/config/WEAK_REORDERING_BEYOND_LLSC) \
    $(wildcard include/config/CPU_LOONGSON3_WORKAROUNDS) \
  arch/mips/include/asm/addrspace.h \
  arch/mips/include/asm/mach-generic/spaces.h \
    $(wildcard include/config/MIPS_AUTO_PFN_OFFSET) \
    $(wildcard include/config/32BIT) \
  arch/mips/include/asm/mipsregs.h \
    $(wildcard include/config/CPU_VR41XX) \
    $(wildcard include/config/PAGE_SIZE_4KB) \
    $(wildcard include/config/PAGE_SIZE_8KB) \
    $(wildcard include/config/PAGE_SIZE_16KB) \
    $(wildcard include/config/PAGE_SIZE_32KB) \
    $(wildcard include/config/PAGE_SIZE_64KB) \
    $(wildcard include/config/MIPS_HUGE_TLB_SUPPORT) \
    $(wildcard include/config/CPU_LOONGSON64) \
    $(wildcard include/config/XPA) \
    $(wildcard include/config/SYS_SUPPORTS_MIPS16) \
    $(wildcard include/config/SYS_SUPPORTS_MICROMIPS) \
    $(wildcard include/config/CPU_MICROMIPS) \
    $(wildcard include/config/WAR_MIPS34K_MISSED_ITLB) \
  arch/mips/include/asm/hazards.h \
    $(wildcard include/config/CPU_MIPSR2) \
    $(wildcard include/config/CPU_MIPSR1) \
    $(wildcard include/config/MIPS_ALCHEMY) \
    $(wildcard include/config/CPU_BMIPS) \
    $(wildcard include/config/CPU_LOONGSON2EF) \
    $(wildcard include/config/CPU_R10000) \
    $(wildcard include/config/CPU_R5500) \
    $(wildcard include/config/CPU_XLR) \
    $(wildcard include/config/CPU_SB1) \
  arch/mips/include/asm/isa-rev.h \
  arch/mips/include/asm/war.h \
    $(wildcard include/config/CPU_R4000_WORKAROUNDS) \
    $(wildcard include/config/CPU_R4400_WORKAROUNDS) \
    $(wildcard include/config/CPU_DADDI_WORKAROUNDS) \
  arch/mips/include/asm/sync.h \
    $(wildcard include/config/CPU_HAS_SYNC) \
  include/asm-generic/barrier.h \
  arch/mips/include/uapi/asm/byteorder.h \
  include/linux/byteorder/big_endian.h \
  include/uapi/linux/byteorder/big_endian.h \
  include/linux/swab.h \
  include/uapi/linux/swab.h \
  arch/mips/include/uapi/asm/swab.h \
  include/linux/byteorder/generic.h \
  arch/mips/include/asm/cpu-features.h \
    $(wildcard include/config/MIPS_FP_SUPPORT) \
    $(wildcard include/config/CPU_MIPSR2_IRQ_VI) \
    $(wildcard include/config/CPU_MIPSR2_IRQ_EI) \
    $(wildcard include/config/CPU_HAS_MSA) \
    $(wildcard include/config/MIPS_MT_SMP) \
    $(wildcard include/config/GENERIC_ATOMIC64) \
  arch/mips/include/asm/cpu.h \
  arch/mips/include/asm/cpu-info.h \
    $(wildcard include/config/MIPS_ASID_BITS_VARIABLE) \
    $(wildcard include/config/CPU_LOONGSON3_CPUCFG_EMULATION) \
    $(wildcard include/config/MIPS_ASID_SHIFT) \
    $(wildcard include/config/MIPS_ASID_BITS) \
  include/linux/cache.h \
    $(wildcard include/config/ARCH_HAS_CACHE_LINE_SIZE) \
  arch/mips/include/asm/cache.h \
    $(wildcard include/config/MIPS_L1_CACHE_SHIFT) \
  arch/mips/include/asm/mach-generic/kmalloc.h \
    $(wildcard include/config/DMA_NONCOHERENT) \
  arch/mips/include/asm/mach-ath79/cpu-feature-overrides.h \
  arch/mips/include/asm/llsc.h \
    $(wildcard include/config/WAR_R10000_LLSC) \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/ffz.h \
  include/asm-generic/bitops/find.h \
    $(wildcard include/config/GENERIC_FIND_FIRST_BIT) \
  include/asm-generic/bitops/sched.h \
  arch/mips/include/asm/arch_hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/le.h \
  include/asm-generic/bitops/ext2-atomic.h \
  include/linux/kstrtox.h \
  include/linux/log2.h \
    $(wildcard include/config/ARCH_HAS_ILOG2_U32) \
    $(wildcard include/config/ARCH_HAS_ILOG2_U64) \
  include/linux/math.h \
  arch/mips/include/asm/div64.h \
  include/asm-generic/div64.h \
  include/linux/minmax.h \
  include/linux/panic.h \
    $(wildcard include/config/PANIC_TIMEOUT) \
  include/linux/printk.h \
    $(wildcard include/config/MESSAGE_LOGLEVEL_DEFAULT) \
    $(wildcard include/config/CONSOLE_LOGLEVEL_DEFAULT) \
    $(wildcard include/config/CONSOLE_LOGLEVEL_QUIET) \
    $(wildcard include/config/EARLY_PRINTK) \
    $(wildcard include/config/PRINTK) \
    $(wildcard include/config/DYNAMIC_DEBUG) \
    $(wildcard include/config/DYNAMIC_DEBUG_CORE) \
  include/linux/init.h \
    $(wildcard include/config/STRICT_KERNEL_RWX) \
    $(wildcard include/config/STRICT_MODULE_RWX) \
    $(wildcard include/config/LTO_CLANG) \
  include/linux/kern_levels.h \
  include/linux/ratelimit_types.h \
  include/uapi/linux/param.h \
  arch/mips/include/uapi/asm/param.h \
  include/asm-generic/param.h \
    $(wildcard include/config/HZ) \
  include/uapi/asm-generic/param.h \
  include/linux/spinlock_types.h \
    $(wildcard include/config/PREEMPT_RT) \
    $(wildcard include/config/DEBUG_LOCK_ALLOC) \
  include/linux/spinlock_types_raw.h \
    $(wildcard include/config/DEBUG_SPINLOCK) \
  include/linux/spinlock_types_up.h \
  include/linux/lockdep_types.h \
    $(wildcard include/config/PROVE_RAW_LOCK_NESTING) \
    $(wildcard include/config/PREEMPT_LOCK) \
    $(wildcard include/config/LOCKDEP) \
    $(wildcard include/config/LOCK_STAT) \
  include/linux/rwlock_types.h \
  include/linux/once_lite.h \
  include/linux/static_call_types.h \
    $(wildcard include/config/HAVE_STATIC_CALL) \
  include/linux/stat.h \
  arch/mips/include/uapi/asm/stat.h \
  include/uapi/linux/stat.h \
  include/linux/time.h \
    $(wildcard include/config/POSIX_TIMERS) \
  include/linux/math64.h \
    $(wildcard include/config/ARCH_SUPPORTS_INT128) \
  include/vdso/math64.h \
  include/linux/time64.h \
  include/vdso/time64.h \
  include/uapi/linux/time.h \
  include/uapi/linux/time_types.h \
  include/linux/time32.h \
  include/linux/timex.h \
  include/uapi/linux/timex.h \
  arch/mips/include/asm/timex.h \
  arch/mips/include/asm/cpu-type.h \
    $(wildcard include/config/SYS_HAS_CPU_LOONGSON2E) \
    $(wildcard include/config/SYS_HAS_CPU_LOONGSON2F) \
    $(wildcard include/config/SYS_HAS_CPU_LOONGSON64) \
    $(wildcard include/config/SYS_HAS_CPU_LOONGSON1B) \
    $(wildcard include/config/SYS_HAS_CPU_LOONGSON1C) \
    $(wildcard include/config/SYS_HAS_CPU_MIPS32_R1) \
    $(wildcard include/config/SYS_HAS_CPU_MIPS32_R2) \
    $(wildcard include/config/SYS_HAS_CPU_MIPS32_R5) \
    $(wildcard include/config/SYS_HAS_CPU_MIPS32_R6) \
    $(wildcard include/config/SYS_HAS_CPU_MIPS64_R2) \
    $(wildcard include/config/SYS_HAS_CPU_MIPS64_R5) \
    $(wildcard include/config/SYS_HAS_CPU_MIPS64_R6) \
    $(wildcard include/config/SYS_HAS_CPU_MIPS64_R1) \
    $(wildcard include/config/SYS_HAS_CPU_R3000) \
    $(wildcard include/config/SYS_HAS_CPU_TX39XX) \
    $(wildcard include/config/SYS_HAS_CPU_VR41XX) \
    $(wildcard include/config/SYS_HAS_CPU_R4300) \
    $(wildcard include/config/SYS_HAS_CPU_R4X00) \
    $(wildcard include/config/SYS_HAS_CPU_TX49XX) \
    $(wildcard include/config/SYS_HAS_CPU_R5000) \
    $(wildcard include/config/SYS_HAS_CPU_R5500) \
    $(wildcard include/config/SYS_HAS_CPU_NEVADA) \
    $(wildcard include/config/SYS_HAS_CPU_R10000) \
    $(wildcard include/config/SYS_HAS_CPU_RM7000) \
    $(wildcard include/config/SYS_HAS_CPU_SB1) \
    $(wildcard include/config/SYS_HAS_CPU_CAVIUM_OCTEON) \
    $(wildcard include/config/SYS_HAS_CPU_BMIPS32_3300) \
    $(wildcard include/config/SYS_HAS_CPU_BMIPS4350) \
    $(wildcard include/config/SYS_HAS_CPU_BMIPS4380) \
    $(wildcard include/config/SYS_HAS_CPU_BMIPS5000) \
    $(wildcard include/config/SYS_HAS_CPU_XLP) \
    $(wildcard include/config/SYS_HAS_CPU_XLR) \
  include/linux/smp.h \
    $(wildcard include/config/UP_LATE_INIT) \
    $(wildcard include/config/DEBUG_PREEMPT) \
  include/linux/errno.h \
  include/uapi/linux/errno.h \
  arch/mips/include/asm/errno.h \
  arch/mips/include/uapi/asm/errno.h \
  include/uapi/asm-generic/errno-base.h \
  include/linux/cpumask.h \
    $(wildcard include/config/CPUMASK_OFFSTACK) \
    $(wildcard include/config/HOTPLUG_CPU) \
    $(wildcard include/config/DEBUG_PER_CPU_MAPS) \
  include/linux/threads.h \
    $(wildcard include/config/NR_CPUS) \
    $(wildcard include/config/BASE_SMALL) \
  include/linux/bitmap.h \
  include/linux/string.h \
    $(wildcard include/config/BINARY_PRINTF) \
    $(wildcard include/config/FORTIFY_SOURCE) \
  include/uapi/linux/string.h \
  arch/mips/include/asm/string.h \
  include/linux/fortify-string.h \
  include/linux/atomic.h \
  arch/mips/include/asm/atomic.h \
  include/linux/irqflags.h \
    $(wildcard include/config/TRACE_IRQFLAGS) \
    $(wildcard include/config/IRQSOFF_TRACER) \
    $(wildcard include/config/PREEMPT_TRACER) \
    $(wildcard include/config/DEBUG_IRQFLAGS) \
    $(wildcard include/config/TRACE_IRQFLAGS_SUPPORT) \
  arch/mips/include/asm/irqflags.h \
    $(wildcard include/config/CPU_HAS_DIEI) \
    $(wildcard include/config/CPU_LOONGSON32) \
    $(wildcard include/config/IRQ_MIPS_CPU) \
  arch/mips/include/generated/asm/percpu.h \
  include/asm-generic/percpu.h \
    $(wildcard include/config/HAVE_SETUP_PER_CPU_AREA) \
  include/linux/percpu-defs.h \
    $(wildcard include/config/DEBUG_FORCE_WEAK_PER_CPU) \
    $(wildcard include/config/AMD_MEM_ENCRYPT) \
  arch/mips/include/asm/cmpxchg.h \
  include/linux/bug.h \
    $(wildcard include/config/BUG_ON_DATA_CORRUPTION) \
  arch/mips/include/asm/bug.h \
    $(wildcard include/config/BUG) \
  arch/mips/include/asm/break.h \
  arch/mips/include/uapi/asm/break.h \
  include/asm-generic/bug.h \
    $(wildcard include/config/GENERIC_BUG_RELATIVE_POINTERS) \
    $(wildcard include/config/DEBUG_BUGVERBOSE) \
  include/linux/instrumentation.h \
    $(wildcard include/config/DEBUG_ENTRY) \
  include/asm-generic/cmpxchg-local.h \
  include/linux/atomic/atomic-arch-fallback.h \
  include/asm-generic/atomic64.h \
  include/linux/atomic/atomic-long.h \
  include/linux/atomic/atomic-instrumented.h \
  include/linux/instrumented.h \
  include/linux/smp_types.h \
  include/linux/llist.h \
    $(wildcard include/config/ARCH_HAVE_NMI_SAFE_CMPXCHG) \
  include/vdso/time32.h \
  include/vdso/time.h \
  include/linux/uidgid.h \
    $(wildcard include/config/MULTIUSER) \
    $(wildcard include/config/USER_NS) \
  include/linux/highuid.h \
  include/linux/buildid.h \
    $(wildcard include/config/CRASH_CORE) \
  include/linux/mm_types.h \
    $(wildcard include/config/HAVE_ALIGNED_STRUCT_PAGE) \
    $(wildcard include/config/MEMCG) \
    $(wildcard include/config/USERFAULTFD) \
    $(wildcard include/config/SWAP) \
    $(wildcard include/config/NUMA) \
    $(wildcard include/config/HAVE_ARCH_COMPAT_MMAP_BASES) \
    $(wildcard include/config/MEMBARRIER) \
    $(wildcard include/config/AIO) \
    $(wildcard include/config/MMU_NOTIFIER) \
    $(wildcard include/config/TRANSPARENT_HUGEPAGE) \
    $(wildcard include/config/NUMA_BALANCING) \
    $(wildcard include/config/ARCH_WANT_BATCHED_UNMAP_TLB_FLUSH) \
    $(wildcard include/config/HUGETLB_PAGE) \
    $(wildcard include/config/IOMMU_SUPPORT) \
    $(wildcard include/config/LRU_GEN) \
  include/linux/mm_types_task.h \
    $(wildcard include/config/SPLIT_PTLOCK_CPUS) \
    $(wildcard include/config/ARCH_ENABLE_SPLIT_PMD_PTLOCK) \
  arch/mips/include/asm/page.h \
    $(wildcard include/config/CPU_MIPS32) \
    $(wildcard include/config/EVA) \
    $(wildcard include/config/DEBUG_VIRTUAL) \
    $(wildcard include/config/FLATMEM) \
    $(wildcard include/config/SPARSEMEM) \
  include/linux/pfn.h \
  arch/mips/include/asm/io.h \
  include/asm-generic/iomap.h \
    $(wildcard include/config/HAS_IOPORT_MAP) \
  include/asm-generic/pci_iomap.h \
    $(wildcard include/config/PCI) \
    $(wildcard include/config/NO_GENERIC_PCI_IOPORT_MAP) \
    $(wildcard include/config/GENERIC_PCI_IOMAP) \
  arch/mips/include/asm/pgtable-bits.h \
    $(wildcard include/config/ARCH_HAS_PTE_SPECIAL) \
    $(wildcard include/config/HAVE_ARCH_SOFT_DIRTY) \
    $(wildcard include/config/CPU_R3K_TLB) \
    $(wildcard include/config/CPU_HAS_RIXI) \
  arch/mips/include/asm/processor.h \
    $(wildcard include/config/MIPS_VA_BITS_48) \
    $(wildcard include/config/CPU_LITTLE_ENDIAN) \
    $(wildcard include/config/CAVIUM_OCTEON_CVMSEG_SIZE) \
    $(wildcard include/config/CPU_XLP) \
    $(wildcard include/config/MIPS_MT_FPAFF) \
    $(wildcard include/config/CPU_HAS_PREFETCH) \
  include/linux/sizes.h \
  arch/mips/include/uapi/asm/cachectl.h \
  arch/mips/include/asm/dsemul.h \
  arch/mips/include/asm/inst.h \
  arch/mips/include/uapi/asm/inst.h \
  arch/mips/include/uapi/asm/bitfield.h \
  arch/mips/include/asm/prefetch.h \
  arch/mips/include/asm/vdso/processor.h \
  arch/mips/include/asm/mach-ath79/mangle-port.h \
    $(wildcard include/config/PCI_AR71XX) \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/SPARSEMEM_VMEMMAP) \
  include/asm-generic/getorder.h \
  include/linux/auxvec.h \
  include/uapi/linux/auxvec.h \
  arch/mips/include/uapi/asm/auxvec.h \
  include/linux/spinlock.h \
    $(wildcard include/config/PREEMPTION) \
  include/linux/preempt.h \
    $(wildcard include/config/PREEMPT_COUNT) \
    $(wildcard include/config/TRACE_PREEMPT_TOGGLE) \
    $(wildcard include/config/PREEMPT_NOTIFIERS) \
  arch/mips/include/generated/asm/preempt.h \
  include/asm-generic/preempt.h \
  include/linux/thread_info.h \
    $(wildcard include/config/THREAD_INFO_IN_TASK) \
    $(wildcard include/config/GENERIC_ENTRY) \
    $(wildcard include/config/HAVE_ARCH_WITHIN_STACK_FRAMES) \
    $(wildcard include/config/HARDENED_USERCOPY) \
  include/linux/restart_block.h \
  arch/mips/include/asm/thread_info.h \
    $(wildcard include/config/MIPS_PGD_C0_CONTEXT) \
  include/linux/bottom_half.h \
  include/linux/lockdep.h \
    $(wildcard include/config/DEBUG_LOCKING_API_SELFTESTS) \
  arch/mips/include/asm/mmiowb.h \
  include/asm-generic/mmiowb.h \
    $(wildcard include/config/MMIOWB) \
  include/linux/spinlock_up.h \
  include/linux/rwlock.h \
    $(wildcard include/config/PREEMPT) \
  include/linux/spinlock_api_up.h \
  include/linux/rbtree.h \
  include/linux/rbtree_types.h \
  include/linux/rcupdate.h \
    $(wildcard include/config/PREEMPT_RCU) \
    $(wildcard include/config/TINY_RCU) \
    $(wildcard include/config/TASKS_RCU_GENERIC) \
    $(wildcard include/config/RCU_STALL_COMMON) \
    $(wildcard include/config/NO_HZ_FULL) \
    $(wildcard include/config/RCU_NOCB_CPU) \
    $(wildcard include/config/TASKS_RCU) \
    $(wildcard include/config/TASKS_TRACE_RCU) \
    $(wildcard include/config/TASKS_RUDE_RCU) \
    $(wildcard include/config/TREE_RCU) \
    $(wildcard include/config/DEBUG_OBJECTS_RCU_HEAD) \
    $(wildcard include/config/PROVE_RCU) \
    $(wildcard include/config/ARCH_WEAK_RELEASE_ACQUIRE) \
  include/linux/rcutiny.h \
    $(wildcard include/config/SRCU) \
  include/linux/rwsem.h \
    $(wildcard include/config/RWSEM_SPIN_ON_OWNER) \
    $(wildcard include/config/DEBUG_RWSEMS) \
  include/linux/err.h \
  include/linux/completion.h \
  include/linux/swait.h \
  include/linux/wait.h \
  arch/mips/include/generated/asm/current.h \
  include/asm-generic/current.h \
  include/uapi/linux/wait.h \
  include/linux/uprobes.h \
    $(wildcard include/config/UPROBES) \
  include/linux/page-flags-layout.h \
    $(wildcard include/config/KASAN_HW_TAGS) \
  include/linux/numa.h \
    $(wildcard include/config/NODES_SHIFT) \
    $(wildcard include/config/NUMA_KEEP_MEMINFO) \
  include/generated/bounds.h \
  include/linux/workqueue.h \
    $(wildcard include/config/DEBUG_OBJECTS_WORK) \
    $(wildcard include/config/FREEZER) \
    $(wildcard include/config/WQ_WATCHDOG) \
  include/linux/timer.h \
    $(wildcard include/config/DEBUG_OBJECTS_TIMERS) \
    $(wildcard include/config/NO_HZ_COMMON) \
  include/linux/ktime.h \
  include/linux/jiffies.h \
  include/vdso/jiffies.h \
  include/generated/timeconst.h \
  include/vdso/ktime.h \
  include/linux/timekeeping.h \
    $(wildcard include/config/GENERIC_CMOS_UPDATE) \
  include/linux/clocksource_ids.h \
  include/linux/debugobjects.h \
    $(wildcard include/config/DEBUG_OBJECTS) \
    $(wildcard include/config/DEBUG_OBJECTS_FREE) \
  include/linux/seqlock.h \
  include/linux/mutex.h \
    $(wildcard include/config/MUTEX_SPIN_ON_OWNER) \
    $(wildcard include/config/DEBUG_MUTEXES) \
  include/linux/osq_lock.h \
  include/linux/debug_locks.h \
  include/linux/ww_mutex.h \
    $(wildcard include/config/DEBUG_RT_MUTEXES) \
    $(wildcard include/config/DEBUG_WW_MUTEX_SLOWPATH) \
  include/linux/rtmutex.h \
  arch/mips/include/asm/mmu.h \
  include/linux/kmod.h \
  include/linux/umh.h \
  include/linux/gfp.h \
    $(wildcard include/config/HIGHMEM) \
    $(wildcard include/config/ZONE_DMA) \
    $(wildcard include/config/ZONE_DMA32) \
    $(wildcard include/config/ZONE_DEVICE) \
    $(wildcard include/config/PM_SLEEP) \
    $(wildcard include/config/CONTIG_ALLOC) \
    $(wildcard include/config/CMA) \
  include/linux/mmdebug.h \
    $(wildcard include/config/DEBUG_VM) \
    $(wildcard include/config/DEBUG_VM_PGFLAGS) \
  include/linux/mmzone.h \
    $(wildcard include/config/FORCE_MAX_ZONEORDER) \
    $(wildcard include/config/MEMORY_ISOLATION) \
    $(wildcard include/config/ZSMALLOC) \
    $(wildcard include/config/SHADOW_CALL_STACK) \
    $(wildcard include/config/LRU_GEN_STATS) \
    $(wildcard include/config/MEMORY_HOTPLUG) \
    $(wildcard include/config/COMPACTION) \
    $(wildcard include/config/PAGE_EXTENSION) \
    $(wildcard include/config/DEFERRED_STRUCT_PAGE_INIT) \
    $(wildcard include/config/HAVE_MEMORYLESS_NODES) \
    $(wildcard include/config/SPARSEMEM_EXTREME) \
    $(wildcard include/config/HAVE_ARCH_PFN_VALID) \
  include/linux/list_nulls.h \
  include/linux/nodemask.h \
  include/linux/pageblock-flags.h \
    $(wildcard include/config/HUGETLB_PAGE_SIZE_VARIABLE) \
  include/linux/page-flags.h \
    $(wildcard include/config/ARCH_USES_PG_UNCACHED) \
    $(wildcard include/config/MEMORY_FAILURE) \
    $(wildcard include/config/PAGE_IDLE_FLAG) \
    $(wildcard include/config/THP_SWAP) \
    $(wildcard include/config/KSM) \
  include/linux/local_lock.h \
  include/linux/local_lock_internal.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/ARCH_HAS_ADD_PAGES) \
    $(wildcard include/config/HAVE_ARCH_NODEDATA_EXTENSION) \
    $(wildcard include/config/MEMORY_HOTREMOVE) \
  include/linux/notifier.h \
  include/linux/srcu.h \
    $(wildcard include/config/TINY_SRCU) \
  include/linux/rcu_segcblist.h \
  include/linux/srcutiny.h \
  include/linux/topology.h \
    $(wildcard include/config/USE_PERCPU_NUMA_NODE_ID) \
    $(wildcard include/config/SCHED_SMT) \
  include/linux/arch_topology.h \
    $(wildcard include/config/GENERIC_ARCH_TOPOLOGY) \
  include/linux/percpu.h \
    $(wildcard include/config/NEED_PER_CPU_EMBED_FIRST_CHUNK) \
    $(wildcard include/config/NEED_PER_CPU_PAGE_FIRST_CHUNK) \
  arch/mips/include/asm/topology.h \
  arch/mips/include/asm/mach-generic/topology.h \
  include/asm-generic/topology.h \
  include/linux/sysctl.h \
    $(wildcard include/config/SYSCTL) \
  include/uapi/linux/sysctl.h \
  include/linux/elf.h \
    $(wildcard include/config/ARCH_USE_GNU_PROPERTY) \
    $(wildcard include/config/ARCH_HAVE_ELF_PROT) \
  arch/mips/include/asm/elf.h \
    $(wildcard include/config/MIPS_O32_FP64_SUPPORT) \
    $(wildcard include/config/MIPS32_N32) \
    $(wildcard include/config/MIPS32_O32) \
    $(wildcard include/config/MIPS32_COMPAT) \
  include/linux/fs.h \
    $(wildcard include/config/READ_ONLY_THP_FOR_FS) \
    $(wildcard include/config/FS_POSIX_ACL) \
    $(wildcard include/config/SECURITY) \
    $(wildcard include/config/CGROUP_WRITEBACK) \
    $(wildcard include/config/IMA) \
    $(wildcard include/config/FILE_LOCKING) \
    $(wildcard include/config/FSNOTIFY) \
    $(wildcard include/config/FS_ENCRYPTION) \
    $(wildcard include/config/FS_VERITY) \
    $(wildcard include/config/EPOLL) \
    $(wildcard include/config/UNICODE) \
    $(wildcard include/config/COMPAT) \
    $(wildcard include/config/QUOTA) \
    $(wildcard include/config/FS_DAX) \
    $(wildcard include/config/BLOCK) \
    $(wildcard include/config/MIGRATION) \
  include/linux/wait_bit.h \
  include/linux/kdev_t.h \
  include/uapi/linux/kdev_t.h \
  include/linux/dcache.h \
  include/linux/rculist.h \
    $(wildcard include/config/PROVE_RCU_LIST) \
  include/linux/rculist_bl.h \
  include/linux/list_bl.h \
  include/linux/bit_spinlock.h \
  include/linux/lockref.h \
    $(wildcard include/config/ARCH_USE_CMPXCHG_LOCKREF) \
  include/linux/stringhash.h \
    $(wildcard include/config/DCACHE_WORD_ACCESS) \
  include/linux/hash.h \
    $(wildcard include/config/HAVE_ARCH_HASH) \
  include/linux/path.h \
  include/linux/list_lru.h \
    $(wildcard include/config/MEMCG_KMEM) \
  include/linux/shrinker.h \
  include/linux/radix-tree.h \
  include/linux/xarray.h \
    $(wildcard include/config/XARRAY_MULTI) \
  include/linux/kconfig.h \
  include/linux/pid.h \
  include/linux/refcount.h \
  include/linux/capability.h \
  include/uapi/linux/capability.h \
  include/linux/semaphore.h \
  include/linux/fcntl.h \
    $(wildcard include/config/ARCH_32BIT_OFF_T) \
  include/uapi/linux/fcntl.h \
  arch/mips/include/uapi/asm/fcntl.h \
  include/uapi/asm-generic/fcntl.h \
  include/uapi/linux/openat2.h \
  include/linux/migrate_mode.h \
  include/linux/percpu-rwsem.h \
  include/linux/rcuwait.h \
  include/linux/sched/signal.h \
    $(wildcard include/config/SCHED_AUTOGROUP) \
    $(wildcard include/config/BSD_PROCESS_ACCT) \
    $(wildcard include/config/TASKSTATS) \
    $(wildcard include/config/AUDIT) \
    $(wildcard include/config/STACK_GROWSUP) \
  include/linux/signal.h \
    $(wildcard include/config/PROC_FS) \
  include/linux/signal_types.h \
    $(wildcard include/config/OLD_SIGACTION) \
  include/uapi/linux/signal.h \
  arch/mips/include/asm/signal.h \
    $(wildcard include/config/TRAD_SIGNALS) \
  arch/mips/include/uapi/asm/signal.h \
  include/uapi/asm-generic/signal-defs.h \
  arch/mips/include/asm/sigcontext.h \
  arch/mips/include/uapi/asm/sigcontext.h \
  arch/mips/include/uapi/asm/siginfo.h \
  include/uapi/asm-generic/siginfo.h \
  include/linux/sched.h \
    $(wildcard include/config/VIRT_CPU_ACCOUNTING_NATIVE) \
    $(wildcard include/config/SCHED_INFO) \
    $(wildcard include/config/SCHEDSTATS) \
    $(wildcard include/config/FAIR_GROUP_SCHED) \
    $(wildcard include/config/RT_GROUP_SCHED) \
    $(wildcard include/config/RT_MUTEXES) \
    $(wildcard include/config/UCLAMP_TASK) \
    $(wildcard include/config/UCLAMP_BUCKETS_COUNT) \
    $(wildcard include/config/KMAP_LOCAL) \
    $(wildcard include/config/SCHED_CORE) \
    $(wildcard include/config/CGROUP_SCHED) \
    $(wildcard include/config/BLK_DEV_IO_TRACE) \
    $(wildcard include/config/PSI) \
    $(wildcard include/config/COMPAT_BRK) \
    $(wildcard include/config/CGROUPS) \
    $(wildcard include/config/BLK_CGROUP) \
    $(wildcard include/config/PAGE_OWNER) \
    $(wildcard include/config/EVENTFD) \
    $(wildcard include/config/STACKPROTECTOR) \
    $(wildcard include/config/ARCH_HAS_SCALED_CPUTIME) \
    $(wildcard include/config/VIRT_CPU_ACCOUNTING_GEN) \
    $(wildcard include/config/POSIX_CPUTIMERS) \
    $(wildcard include/config/POSIX_CPU_TIMERS_TASK_WORK) \
    $(wildcard include/config/KEYS) \
    $(wildcard include/config/SYSVIPC) \
    $(wildcard include/config/DETECT_HUNG_TASK) \
    $(wildcard include/config/IO_URING) \
    $(wildcard include/config/AUDITSYSCALL) \
    $(wildcard include/config/UBSAN) \
    $(wildcard include/config/UBSAN_TRAP) \
    $(wildcard include/config/TASK_XACCT) \
    $(wildcard include/config/CPUSETS) \
    $(wildcard include/config/X86_CPU_RESCTRL) \
    $(wildcard include/config/FUTEX) \
    $(wildcard include/config/PERF_EVENTS) \
    $(wildcard include/config/RSEQ) \
    $(wildcard include/config/TASK_DELAY_ACCT) \
    $(wildcard include/config/FAULT_INJECTION) \
    $(wildcard include/config/LATENCYTOP) \
    $(wildcard include/config/KUNIT) \
    $(wildcard include/config/FUNCTION_GRAPH_TRACER) \
    $(wildcard include/config/BCACHE) \
    $(wildcard include/config/VMAP_STACK) \
    $(wildcard include/config/BPF_SYSCALL) \
    $(wildcard include/config/GCC_PLUGIN_STACKLEAK) \
    $(wildcard include/config/X86_MCE) \
    $(wildcard include/config/KRETPROBES) \
    $(wildcard include/config/ARCH_HAS_PARANOID_L1D_FLUSH) \
    $(wildcard include/config/ARCH_TASK_STRUCT_ON_STACK) \
    $(wildcard include/config/DEBUG_RSEQ) \
  include/uapi/linux/sched.h \
  include/linux/sem.h \
  include/uapi/linux/sem.h \
  include/linux/ipc.h \
  include/linux/rhashtable-types.h \
  include/uapi/linux/ipc.h \
  arch/mips/include/generated/uapi/asm/ipcbuf.h \
  include/uapi/asm-generic/ipcbuf.h \
  arch/mips/include/uapi/asm/sembuf.h \
  include/linux/shm.h \
  include/uapi/linux/shm.h \
  include/uapi/asm-generic/hugetlb_encode.h \
  arch/mips/include/uapi/asm/shmbuf.h \
  arch/mips/include/asm/shmparam.h \
  include/linux/plist.h \
    $(wildcard include/config/DEBUG_PLIST) \
  include/linux/hrtimer.h \
    $(wildcard include/config/HIGH_RES_TIMERS) \
    $(wildcard include/config/TIME_LOW_RES) \
    $(wildcard include/config/TIMERFD) \
  include/linux/hrtimer_defs.h \
  include/linux/timerqueue.h \
  include/linux/seccomp.h \
    $(wildcard include/config/SECCOMP) \
    $(wildcard include/config/HAVE_ARCH_SECCOMP_FILTER) \
    $(wildcard include/config/SECCOMP_FILTER) \
    $(wildcard include/config/CHECKPOINT_RESTORE) \
    $(wildcard include/config/SECCOMP_CACHE_DEBUG) \
  include/uapi/linux/seccomp.h \
  arch/mips/include/asm/seccomp.h \
  include/uapi/linux/unistd.h \
  arch/mips/include/asm/unistd.h \
  arch/mips/include/uapi/asm/unistd.h \
  arch/mips/include/generated/uapi/asm/unistd_o32.h \
  arch/mips/include/generated/asm/unistd_nr_n32.h \
  arch/mips/include/generated/asm/unistd_nr_n64.h \
  arch/mips/include/generated/asm/unistd_nr_o32.h \
  include/asm-generic/seccomp.h \
  include/linux/resource.h \
  include/uapi/linux/resource.h \
  arch/mips/include/uapi/asm/resource.h \
  include/asm-generic/resource.h \
  include/uapi/asm-generic/resource.h \
  include/linux/latencytop.h \
  include/linux/sched/prio.h \
  include/linux/sched/types.h \
  include/linux/syscall_user_dispatch.h \
  include/linux/task_io_accounting.h \
    $(wildcard include/config/TASK_IO_ACCOUNTING) \
  include/linux/posix-timers.h \
  include/linux/alarmtimer.h \
    $(wildcard include/config/RTC_CLASS) \
  include/linux/task_work.h \
  include/uapi/linux/rseq.h \
  include/linux/kcsan.h \
  arch/mips/include/generated/asm/kmap_size.h \
  include/asm-generic/kmap_size.h \
    $(wildcard include/config/DEBUG_KMAP_LOCAL) \
  include/linux/sched/jobctl.h \
  include/linux/sched/task.h \
    $(wildcard include/config/HAVE_EXIT_THREAD) \
    $(wildcard include/config/ARCH_WANTS_DYNAMIC_TASK_STRUCT) \
    $(wildcard include/config/HAVE_ARCH_THREAD_STRUCT_WHITELIST) \
  include/linux/uaccess.h \
    $(wildcard include/config/SET_FS) \
  include/linux/fault-inject-usercopy.h \
    $(wildcard include/config/FAULT_INJECTION_USERCOPY) \
  arch/mips/include/asm/uaccess.h \
  arch/mips/include/asm/asm-eva.h \
  arch/mips/include/asm/extable.h \
  include/linux/cred.h \
    $(wildcard include/config/DEBUG_CREDENTIALS) \
  include/linux/key.h \
    $(wildcard include/config/KEY_NOTIFICATIONS) \
    $(wildcard include/config/NET) \
  include/linux/assoc_array.h \
    $(wildcard include/config/ASSOCIATIVE_ARRAY) \
  include/linux/sched/user.h \
    $(wildcard include/config/WATCH_QUEUE) \
  include/linux/percpu_counter.h \
  include/linux/ratelimit.h \
  arch/mips/include/asm/ptrace.h \
    $(wildcard include/config/CPU_HAS_SMARTMIPS) \
  arch/mips/include/asm/isadep.h \
    $(wildcard include/config/CPU_R3000) \
    $(wildcard include/config/CPU_TX39XX) \
  arch/mips/include/uapi/asm/ptrace.h \
  include/linux/rcu_sync.h \
  include/linux/delayed_call.h \
  include/linux/uuid.h \
  include/uapi/linux/uuid.h \
  include/linux/errseq.h \
  include/linux/ioprio.h \
  include/linux/sched/rt.h \
  include/linux/iocontext.h \
  include/uapi/linux/ioprio.h \
  include/linux/fs_types.h \
  include/linux/mount.h \
  include/linux/mnt_idmapping.h \
  include/uapi/linux/fs.h \
  include/uapi/linux/ioctl.h \
  arch/mips/include/uapi/asm/ioctl.h \
  include/asm-generic/ioctl.h \
  include/uapi/asm-generic/ioctl.h \
  include/linux/quota.h \
    $(wildcard include/config/QUOTA_NETLINK_INTERFACE) \
  include/uapi/linux/dqblk_xfs.h \
  include/linux/dqblk_v1.h \
  include/linux/dqblk_v2.h \
  include/linux/dqblk_qtree.h \
  include/linux/projid.h \
  include/uapi/linux/quota.h \
  include/linux/nfs_fs_i.h \
  include/uapi/linux/elf.h \
  include/uapi/linux/elf-em.h \
  arch/mips/include/uapi/asm/hwcap.h \
  include/linux/kobject.h \
    $(wildcard include/config/UEVENT_HELPER) \
    $(wildcard include/config/DEBUG_KOBJECT_RELEASE) \
  include/linux/sysfs.h \
  include/linux/kernfs.h \
    $(wildcard include/config/KERNFS) \
  include/linux/idr.h \
  include/linux/kobject_ns.h \
  include/linux/kref.h \
  include/linux/moduleparam.h \
    $(wildcard include/config/ALPHA) \
    $(wildcard include/config/IA64) \
    $(wildcard include/config/PPC64) \
  include/linux/jump_label.h \
    $(wildcard include/config/HAVE_ARCH_JUMP_LABEL_RELATIVE) \
  include/linux/rbtree_latch.h \
  include/linux/error-injection.h \
  include/asm-generic/error-injection.h \
  include/linux/tracepoint-defs.h \
  include/linux/static_key.h \
  include/linux/cfi.h \
    $(wildcard include/config/CFI_CLANG_SHADOW) \
  arch/mips/include/asm/module.h \
  include/linux/build-salt.h \
    $(wildcard include/config/BUILD_SALT) \
  include/linux/elfnote.h \
  include/linux/elfnote-lto.h \
    $(wildcard include/config/LTO) \
  include/linux/vermagic.h \
  include/generated/utsrelease.h \
  arch/mips/include/asm/vermagic.h \
    $(wildcard include/config/CPU_MIPS32_R1) \
    $(wildcard include/config/CPU_MIPS32_R2) \
    $(wildcard include/config/CPU_MIPS32_R5) \
    $(wildcard include/config/CPU_MIPS32_R6) \
    $(wildcard include/config/CPU_MIPS64_R1) \
    $(wildcard include/config/CPU_MIPS64_R2) \
    $(wildcard include/config/CPU_MIPS64_R5) \
    $(wildcard include/config/CPU_MIPS64_R6) \
    $(wildcard include/config/CPU_R4300) \
    $(wildcard include/config/CPU_R4X00) \
    $(wildcard include/config/CPU_TX49XX) \
    $(wildcard include/config/CPU_R5000) \
    $(wildcard include/config/CPU_NEVADA) \
    $(wildcard include/config/CPU_RM7000) \
    $(wildcard include/config/CPU_P5600) \

/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/linux-ath79_generic/gpio-button-hotplug/gpio-button-hotplug.mod.o: $(deps_/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/linux-ath79_generic/gpio-button-hotplug/gpio-button-hotplug.mod.o)

$(deps_/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/linux-ath79_generic/gpio-button-hotplug/gpio-button-hotplug.mod.o):
