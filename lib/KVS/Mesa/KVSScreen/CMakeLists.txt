# Module name
set(MODULE KVSScreen)
set(MODULE2 KVSStochasticRenderingCompositor)

# Source files
set(SOURCES
  ${MODULE}.cpp
  ${MODULE2}.cpp
  LuaEntry.cpp
  )


# GLEW
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARY})
endif()

find_package(GLUT REQUIRED)
if (GLUT_FOUND)
    include_directories(${GLUT_INCLUDE_DIRS})
    link_libraries(${GLUT_LIBRARY})
endif()

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
