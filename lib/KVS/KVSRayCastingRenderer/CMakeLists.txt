# Module name
set(MODULE KVSRayCastingRenderer)

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

find_package(GLUT REQUIRED)
if (GLUT_FOUND)
   include_directories(${GLUT_INCLUDE_DIR})
   link_libraries(${GLUT_LIBRARY})
endif()

# link OpenGL libraries
# NOT WORKING
target_link_libraries(${MODULE} ${GLUT_LIBRARY})

# link KVS libeog im	
target_link_libraries(${MODULE} kvsCore)
target_link_libraries(${MODULE} kvsSupportGLUT)

# link HiveCore lib
target_link_libraries(${MODULE} hiveCore)

