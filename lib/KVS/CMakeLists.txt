# fPIC
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

# HIVE
set(HIVE_DIR ${CMAKE_SOURCE_DIR})
set(KVS_DIR  ${CMAKE_SOURCE_DIR}/third_party/local/kvs)

# Headers
set(INCLUDES
  ${KVS_DIR}/include
  ${HIVE_DIR}/include
  ${HIVE_DIR}/include/Core
  ${HIVE_DIR}/include/Buffer
  ${HIVE_DIR}/include/SceneScript
  ${HIVE_DIR}/third_party/lua/src
  ${CMAKE_BINARY_DIR}/third_party/lua

  )
include_directories(${INCLUDES})

# Library path
link_directories(${KVS_DIR}/lib)
link_directories(${HIVE_DIR}/build/bin)

# Libraries
set(LIBRARIES
  hiveCore
  lua
  )

# Check KVS_ENABLE_OSMESA
execute_process(
  COMMAND grep KVS_ENABLE_OSMESA ${KVS_DIR}/kvs.conf
  COMMAND cut -d = -f 2
  COMMAND sed "s/ //g"
  OUTPUT_VARIABLE KVS_OSMESA_FLAG
  )

set(KVS_OSMESA_FLAG 0)
if(APPLE OR ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  if(${KVS_OSMESA_FLAG} EQUAL 0)
    find_library(OPENGL OpenGL)
    find_library(GLUT GLUT)
    find_library(GLEW glew)

    if(NOT OPENGL)
      message(FATAL_ERROR "OpenGL Framework not found")
    endif()

    set(LIBRARIES
      ${LIBRARIES}
      ${OPENGL}
      ${GLUT}
      ${GLEW}
      kvsCore
      kvsSupportGLUT
      )
  else()
    set(LIBRARIES
      ${LIBRARIES}
      kvsCore
      OSMesa
      )
  endif()
else() # Linux Non-OSMESA
       # GL GLU GLEW glut 

  # set(CMAKE_SHARED_LINKER_FLAGS
  # "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-no-as-needed"
  #  )
  if(KVS_OSMESA_FLAG EQUAL 0)
    
   find_package(OpenGL REQUIRED)
   if (OpenGL_FOUND)
     # MESSAGE("lib/KVS: OpenGL Library Found !!!")
     include_directories(${OPENGL_INCLUDE_DIR})
     link_libraries(${OPENGL_LIBRARY})
   else()
      message(FATAL_ERROR "OpenGL Framework not found")
    endif()

   find_package(GLEW REQUIRED)
   if (GLEW_FOUND)
     # MESSAGE("lib/KVS: OpenGL Library Found !!!")
     include_directories(${GLEW_INCLUDE_DIR})
     link_libraries(${GLEW_LIBRARY})
   endif()

   find_package(GLUT REQUIRED)
   if (GLUT_FOUND)
     # MESSAGE("lib/KVS: GLUT Library Found !!!")
     include_directories(${GLUT_INCLUDE_DIR})
     link_libraries(${GLUT_LIBRARY})
   endif()

    set(LIBRARIES
      ${LIBRARIES}
      ${OPENGL_LIBRARY}
      ${GLUT_LIBRARY}
      ${GLEW_LIBRARY}
      -Wl,--whole-archive kvsCore -Wl,--no-whole-archive
      -Wl,--whole-archive kvsSupportGLUT -Wl,--no-whole-archive
      )
  else() # Linux OSMESA
    set(LIBRARIES
      ${LIBRARIES}
      kvsCore
      )
  endif()
endif()

# add_subdirectory(KVSAdaptiveParticleBasedRenderer)
#add_subdirectory(KVSCellByCellMetropolisSampling)
# add_subdirectory(KVSCellByCellPointSampling)
#add_subdirectory(KVSCellByCellUniformSampling)
add_subdirectory(KVSDataImporter)
add_subdirectory(KVSExternalFaces)
add_subdirectory(KVSIsosurface)
# add_subdirectory(KVSGenericObject)
# add_subdirectory(KVSTransferEntropy3D)
# add_subdirectory(KVSConvergentCrossMapping3D)
#add_subdirectory(KVSGLSLParticleBasedRenderer)
#add_subdirectory(KVSGLSLRayCastingRenderer)
#add_subdirectory(KVSHAVSVolumeRenderer)
add_subdirectory(KVSHydrogenVolumeData)
add_subdirectory(KVSLineRenderer)
#add_subdirectory(KVSWriteFld)
add_subdirectory(KVSObject)
# add_subdirectory(KVSObjectCompositor)
#add_subdirectory(KVSParticleBasedRenderer)
add_subdirectory(KVSPointGenerator)
add_subdirectory(KVSPolygonImporter)
add_subdirectory(KVSPolygonObject)
add_subdirectory(KVSRayCastingRenderer)
add_subdirectory(KVSRenderObject)
add_subdirectory(KVSSphereGlyph)
add_subdirectory(KVSStochasticPolygonRenderer)
add_subdirectory(KVSStreamline)
add_subdirectory(KVSStructuredVolumeImporter)
add_subdirectory(KVSStylizedLineRenderer)
add_subdirectory(KVSTornadoVolumeData)
add_subdirectory(KVSTransferFunction)
add_subdirectory(KVSUniColor)
add_subdirectory(KVSUnstructuredVolumeImporter)
add_subdirectory(KVSXform)

if(KVS_OSMESA_FLAG EQUAL 0)
  add_subdirectory(Mesa)
#else()
#  add_subdirectory(OSMesa)
endif()
