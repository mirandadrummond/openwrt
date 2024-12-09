cmd_libbb/makedev.o := mips-openwrt-linux-musl-gcc -Wp,-MD,libbb/.makedev.o.d  -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DBB_VER='"1.36.1"' -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -finline-limit=0 -fno-builtin-strlen -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Oz -Os -pipe -mno-branch-likely -mips32r2 -mtune=24kc -fno-caller-saves -fno-plt -fhonour-copts -msoft-float -fmacro-prefix-map=/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/busybox-default/busybox-1.36.1=busybox-1.36.1 -mips16 -minterlink-mips16 -flto=auto -fno-fat-lto-objects -fstack-protector -D_FORTIFY_SOURCE=1 -Wl,-z,now -Wl,-z,relro -I/mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/usr/include -I/mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/fortify -I/mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include   -DKBUILD_BASENAME='"makedev"'  -DKBUILD_MODNAME='"makedev"' -c -o libbb/makedev.o libbb/makedev.c

deps_libbb/makedev.o := \
  libbb/makedev.c \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/stdc-predef.h \
  include/platform.h \
    $(wildcard include/config/werror.h) \
    $(wildcard include/config/big/endian.h) \
    $(wildcard include/config/little/endian.h) \
    $(wildcard include/config/nommu.h) \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/limits.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/features.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/bits/alltypes.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/bits/limits.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/byteswap.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/stdint.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/bits/stdint.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/endian.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/stdbool.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/fortify/unistd.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/unistd.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/bits/posix.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/fortify/fortify-headers.h \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/sys/sysmacros.h \

libbb/makedev.o: $(deps_libbb/makedev.o)

$(deps_libbb/makedev.o):
