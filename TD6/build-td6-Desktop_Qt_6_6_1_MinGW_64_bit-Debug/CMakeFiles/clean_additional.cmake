# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\td6_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\td6_autogen.dir\\ParseCache.txt"
  "td6_autogen"
  )
endif()
