# Module name
set(MODULE KVSIsosurface)

# Source files
set(SOURCES
  ${MODULE}.cpp
  LuaEntry.cpp
  )

# Build as shared library
add_library(${MODULE} SHARED ${SOURCES})
set_target_properties(${MODULE} PROPERTIES PREFIX "")

# Enable address sanitizer(if available).
add_sanitizers(${MODULE})

# link KVS lib
target_link_libraries(${MODULE} kvsCore)
target_link_libraries(${MODULE} kvsSupportGLUT)

# link HiveCore lib
target_link_libraries(${MODULE} hiveCore)


