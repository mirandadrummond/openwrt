cmd_libbb/hash_md5_sha_x86-32_shaNI.o := mips-openwrt-linux-musl-gcc -Wp,-MD,libbb/.hash_md5_sha_x86-32_shaNI.o.d  -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DBB_VER='"1.36.1"' -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -finline-limit=0 -fno-builtin-strlen -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Oz -Os -pipe -mno-branch-likely -mips32r2 -mtune=24kc -fno-caller-saves -fno-plt -fhonour-copts -msoft-float -fmacro-prefix-map=/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/busybox-default/busybox-1.36.1=busybox-1.36.1 -mips16 -minterlink-mips16 -flto=auto -fno-fat-lto-objects -fstack-protector -D_FORTIFY_SOURCE=1 -Wl,-z,now -Wl,-z,relro -I/mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/usr/include -I/mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/fortify -I/mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include      -c -o libbb/hash_md5_sha_x86-32_shaNI.o libbb/hash_md5_sha_x86-32_shaNI.S

deps_libbb/hash_md5_sha_x86-32_shaNI.o := \
  libbb/hash_md5_sha_x86-32_shaNI.S \
    $(wildcard include/config/sha1/hwaccel.h) \
  /mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/include/stdc-predef.h \

libbb/hash_md5_sha_x86-32_shaNI.o: $(deps_libbb/hash_md5_sha_x86-32_shaNI.o)

$(deps_libbb/hash_md5_sha_x86-32_shaNI.o):
