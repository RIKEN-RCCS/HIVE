IF(HIVE_BUILD_WITH_PDMLIB)

add_definitions(-DHIVE_WITH_PDMLIB)

  IF(HIVE_BUILD_WITH_MPI)
    SET(PDMLIB_LIBS
      PDMmpi TPmpi fpzip zoltan z
    )
  ELSE()
    SET(PDMLIB_LIBS
      PDM TP fpzip zoltan z
    )
  ENDIF()

  include_directories(${CMAKE_SOURCE_DIR}/third_party/local/PDMlib/include)
  link_directories(${CMAKE_SOURCE_DIR}/third_party/local/PDMlib/lib)

# Headers
set(INCLUDES
	.
	${CMAKE_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/include/Core
	${CMAKE_SOURCE_DIR}/include/Buffer
        ${CMAKE_SOURCE_DIR}/include/SceneScript
        ${CMAKE_SOURCE_DIR}/third_party/lua/src
        ${CMAKE_BINARY_DIR}/third_party/lua
)
include_directories(${INCLUDES})

# Source files
set(SOURCES
	PdmSaver.cpp
	LuaEntry.cpp
)
add_library(PdmSaver ${HIVE_LIBRARY_TYPE} ${SOURCES})
target_link_libraries(PdmSaver hiveCore)
target_link_libraries(PdmSaver ${PDMLIB_LIBS})
set_target_properties(PdmSaver PROPERTIES PREFIX "")

ENDIF() # HIVE_BUILD_WITH_PDMLIB

 
