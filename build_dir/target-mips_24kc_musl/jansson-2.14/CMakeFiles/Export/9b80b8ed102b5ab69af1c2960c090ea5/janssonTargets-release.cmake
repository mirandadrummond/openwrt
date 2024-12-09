#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "jansson::jansson" for configuration "Release"
set_property(TARGET jansson::jansson APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(jansson::jansson PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libjansson.so.4.14.0"
  IMPORTED_SONAME_RELEASE "libjansson.so.4"
  )

list(APPEND _cmake_import_check_targets jansson::jansson )
list(APPEND _cmake_import_check_files_for_jansson::jansson "${_IMPORT_PREFIX}/lib/libjansson.so.4.14.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
