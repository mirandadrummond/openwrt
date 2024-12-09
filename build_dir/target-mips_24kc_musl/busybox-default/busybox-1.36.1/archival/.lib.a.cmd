cmd_archival/lib.a := rm -f archival/lib.a; mips-openwrt-linux-musl-gcc-ar  rcs archival/lib.a archival/bbunzip.o archival/chksum_and_xwrite_tar_header.o archival/gzip.o archival/tar.o
