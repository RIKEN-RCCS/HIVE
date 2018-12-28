# Module name
set(MODULE KVSStochasticTetrahedraRenderer)

# Source files
set(SOURCES
  ${MODULE}.cpp
  LuaEntry.cpp
  )

# Build as shared library
add_library(${MODULE} SHARED ${SOURCES})
set_target_properties(${MODULE} PROPERTIES PREFIX "")

# Libraries
target_link_libraries(${MODULE} ${LIBRARIES})

# Copy moduledata
file(COPY ${CMAKE_SOURCE_DIR}/moduledata/KVS/Mesa/${MODULE} DESTINATION ${EXECUTABLE_OUTPUT_PATH}/ModuleSystem/moduledata/KVS)
