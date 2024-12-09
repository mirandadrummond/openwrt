# Install script for directory: /mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/uhttpd-2023-06-25-34a8a74d

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/mnt/md0/miranda/openwrt/staging_dir/toolchain-mips_24kc_gcc-12.3.0_musl/bin/mips-openwrt-linux-musl-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/uhttpd-2023-06-25-34a8a74d/uhttpd")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/uhttpd" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/uhttpd")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/uhttpd-2023-06-25-34a8a74d/:" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/uhttpd")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE MODULE FILES "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/uhttpd-2023-06-25-34a8a74d/uhttpd_lua.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/uhttpd_lua.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/uhttpd_lua.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/uhttpd-2023-06-25-34a8a74d/:" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/uhttpd_lua.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE MODULE FILES "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/uhttpd-2023-06-25-34a8a74d/uhttpd_ucode.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/uhttpd_ucode.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/uhttpd_ucode.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/uhttpd-2023-06-25-34a8a74d/:" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/uhttpd_ucode.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE MODULE FILES "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/uhttpd-2023-06-25-34a8a74d/uhttpd_ubus.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/uhttpd_ubus.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/uhttpd_ubus.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/uhttpd-2023-06-25-34a8a74d/:" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/uhttpd_ubus.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/mnt/md0/miranda/openwrt/build_dir/target-mips_24kc_musl/uhttpd-2023-06-25-34a8a74d/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
