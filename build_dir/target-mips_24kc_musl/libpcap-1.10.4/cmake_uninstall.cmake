if(NOT EXISTS "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: /mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/install_manifest.txt")
endif(NOT EXISTS "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/install_manifest.txt")

file(READ "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/libpcap-1.10.4/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling $ENV{DESTDIR}${file}")
  if(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    exec_program(
      "/mnt/md0/miranda/openwrt/staging_dir/host/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing $ENV{DESTDIR}${file}")
    endif(NOT "${rm_retval}" STREQUAL 0)
  else(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    message(STATUS "File $ENV{DESTDIR}${file} does not exist.")
  endif(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
endforeach(file)
