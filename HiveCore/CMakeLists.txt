cmake_minimum_required(VERSION 2.8)
enable_testing()

PROJECT(hrender)

# macros
#add_definitions(-DDEBUG)

# ------------------------------------------------------------

message(CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR})

# --------------------------------------
# 
#  SAME Build Option with SURFACE
#
# Build options
#
# K/FX10 native environment
IF (CMAKE_SYSTEM_PROCESSOR MATCHES "s64fx")

  # Use native Fujitsu compiler
  IF (HIVE_BUILD_WITH_MPI)
    SET(CMAKE_C_COMPILER mpifcc)
    SET(CMAKE_CXX_COMPILER mpiFCC)
  ELSE()
    SET(CMAKE_C_COMPILER fcc)
    SET(CMAKE_CXX_COMPILER FCC)
  ENDIF()

  # gcc compatible flag(-Xg)
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Xg")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xg")

  # PIC flag
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

  # OpenMP flag(-Kopenmp)
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Kopenmp")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Kopenmp")

  IF (CMAKE_BUILD_TYPE MATCHES "Release")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Kfast")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Kfast")
  ENDIF()

  IF (HIVE_BUILD_WITH_PMLIB)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Nfjcex -Ntl_notrt -DK_COMPUTER")
    SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Nfjcex -Ntl_notrt -DK_COMPUTER")
  ENDIF()

  # Prevent CMake from adding GNU-specific linker flags (-rdynamic)
  SET(CMAKE_C_COMPILER_ID "Fujitsu" CACHE STRING "Fujitsu C cross-compiler" FORCE)
  SET(CMAKE_CXX_COMPILER_ID "Fujitsu" CACHE STRING "Fujitsu C++ cross-compiler" FORCE)

  # FindOpenMP.cmake does not try -Kopenmp,but the package will try specific
  # flags based on the compier ID.
  SET(OMP_FLAG_Fujitsu "-Kopenmp")
ENDIF()

# K cross compiling
IF (HIVE_BUILD_K_CROSS_COMPILE)

  # Use Fujitsu cross compiler
  IF (HIVE_BUILD_WITH_MPI)
    SET(CMAKE_C_COMPILER mpifccpx)
    SET(CMAKE_CXX_COMPILER mpiFCCpx)
  ELSE()
    SET(CMAKE_C_COMPILER fccpx)
    SET(CMAKE_CXX_COMPILER FCCpx)
  ENDIF()

  # Prevent CMake from adding GNU-specific linker flags (-rdynamic)
  SET(CMAKE_C_COMPILER_ID "Fujitsu" CACHE STRING "Fujitsu C cross-compiler" FORCE)
  SET(CMAKE_CXX_COMPILER_ID "Fujitsu" CACHE STRING "Fujitsu C++ cross-compiler" FORCE)

  # gcc compatible flag(-Xg)
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Xg")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xg")

  # PIC flag
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

  # OpenMP flag(-Kopenmp)
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Kopenmp")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Kopenmp")

  IF (CMAKE_BUILD_TYPE MATCHES "Release")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Kfast")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Kfast")
  ENDIF()

  IF (HIVE_BUILD_WITH_PMLIB)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Nfjcex -Ntl_notrt -DK_COMPUTER")
    SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Nfjcex -Ntl_notrt -DK_COMPUTER")
  ENDIF()

  # FindOpenMP.cmake does not try -Kopenmp,but the package will try specific
  # flags based on the compiler ID.
  SET(OMP_FLAG_Fujitsu "-Kopenmp")
  
ELSE()
  IF (CMAKE_SYSTEM_PROCESSOR MATCHES "s64fx")
  ELSE () # assume gcc + linux or macosx
    # PIC flag
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

    IF (HIVE_BUILD_WITH_OPENMP)
      SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
      SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
    ENDIF()
  ENDIF()
ENDIF()

# --------------------------------------

# --------------------------------------
# third party lib flags
#

IF(HIVE_BUILD_WITH_COMPOSITOR)
  IF(NOT HIVE_BUILD_WITH_MPI)
    message(FATAL_ERROR "HIVE_BUILD_WITH_MPI must be defined when HIVE_BUILD_WITH_COMPOSIOR is enabled")
  ENDIF()
  add_definitions(-DHIVE_WITH_COMPOSITOR)
ENDIF()

IF(HIVE_BUILD_WITH_PMLIB)
  IF(NOT HIVE_BUILD_WITH_MPI)
    message(FATAL_ERROR "HIVE_BUILD_WITH_MPI must be defined when HIVE_BUILD_WITH_PMLIB is enabled")
  ENDIF()
  add_definitions(-DHIVE_WITH_PMLIB)
ENDIF()
# --------------------------------------

# --------------------------------------
# MPI
IF(HIVE_BUILD_WITH_MPI)
  add_definitions(-DHIVE_ENABLE_MPI)
ENDIF()
# --------------------------------------

# --------------------------------------
# OpenGL
IF(HIVE_BUILD_WITH_OPENGL)
  add_definitions(-DHIVE_BUILD_WITH_OPENGL)
ENDIF()
# --------------------------------------


# Headers
set(INCLUDES
  ${CMAKE_SOURCE_DIR}/third_party/lua/src
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_BINARY_DIR}/third_party/lua/
	${CMAKE_SOURCE_DIR}/third_party/SURFACE/include
	${CMAKE_SOURCE_DIR}/third_party/SURFACE/gles
	${CMAKE_SOURCE_DIR}/third_party/SURFACE/render
	${CMAKE_SOURCE_DIR}/third_party/local
	${CMAKE_SOURCE_DIR}/third_party/local/include
	${CMAKE_SOURCE_DIR}/third_party/local/TextParser/include
	${CMAKE_SOURCE_DIR}/include/Buffer
	${CMAKE_SOURCE_DIR}/include/Network
	${CMAKE_SOURCE_DIR}/include/RenderObject
	${CMAKE_SOURCE_DIR}/include/Renderer
	${CMAKE_SOURCE_DIR}/include/SceneScript
	${CMAKE_SOURCE_DIR}/include/Core
	${CMAKE_SOURCE_DIR}/include/Image
	${CMAKE_SOURCE_DIR}/include/Generator
)
INCLUDE_DIRECTORIES(${INCLUDES})


# Links
set(LIBS
	${CMAKE_BINARY_DIR}/third_party/lua
	${CMAKE_SOURCE_DIR}/third_party/local/lib		# fpzip, zoltan
	${CMAKE_SOURCE_DIR}/third_party/local/TextParser/lib
)
link_directories(${LIBS})


# Source files

set(HIVECORE_SOURCES  
  src/Buffer/bvhtree/render_bvh_tree.cc
  src/Buffer/BufferSparseVolumeData.cpp
  src/Core/Path.cpp
  src/Core/Perf.cpp
  src/Buffer/Buffer.cpp
  src/Buffer/BufferMeshData.cpp
  src/Buffer/BufferVolumeData.cpp
  src/Buffer/BufferLineData.cpp
  src/Buffer/BufferSolidData.cpp
  src/Buffer/BufferPointData.cpp
  src/Buffer/BufferVectorData.cpp
  src/Buffer/BufferTetraData.cpp
  src/Buffer/BufferImageData.cpp
  src/Buffer/BufferExtraData.cpp
  src/Buffer/UserBufferData.cpp
  src/SceneScript/SceneScript.cpp
  src/RenderObject/Camera.cpp
  src/RenderObject/RenderObject.cpp
  src/RenderObject/PolygonModel.cpp
  src/RenderObject/VolumeModel.cpp
  src/RenderObject/SparseVolumeModel.cpp
  src/RenderObject/LineModel.cpp
  src/RenderObject/PointModel.cpp
  src/RenderObject/TetraModel.cpp
  src/RenderObject/SolidModel.cpp
  src/RenderObject/VectorModel.cpp
  src/Image/jpge.cpp
  src/Image/jpgd.cpp
  src/Image/lodepng.cpp
  src/Image/tinyexr.cpp
  src/Image/ImageLoader.cpp
  src/Image/GenTexture.cpp
  src/Image/ImageSaver.cpp
  src/Generator/PrimitiveGenerator.cpp
)

IF(HIVE_BUILD_WITH_COMPOSITOR)

  SET(COMPOSITOR_LIBS
    234comp
  )

  include_directories(${CMAKE_SOURCE_DIR}/third_party/local/234Compositor/include)
  link_directories(${CMAKE_SOURCE_DIR}/third_party/local/234Compositor/lib)
  
ENDIF()

IF(HIVE_BUILD_WITH_PMLIB)
  SET(PMLIB_LIBS
    PMmpi
  )

  include_directories(${CMAKE_SOURCE_DIR}/third_party/local/PMlib/include)
  link_directories(${CMAKE_SOURCE_DIR}/third_party/local/PMlib/lib)
ENDIF()

IF(NOT EXECUTABLE_OUTPUT_PATH)
  SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
ENDIF()

IF(BUILD_SHARED_LIBS)
  SET(HIVE_LIBRARY_TYPE SHARED)
ELSE()
  add_definitions(-DHIVE_STATIC)
ENDIF()

# HIVE Core
add_library (hiveCore ${HIVE_LIBRARY_TYPE} ${HIVECORE_SOURCES})

# Enable address sanitizer(if available).
add_sanitizers(hiveCore)


# LINK_PUBLIC is required since liblua needs to be linked as a dynamic library.
target_link_libraries(hiveCore LINK_PUBLIC liblua)

# Additional Libraries
if (APPLE OR ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    if(HIVE_BUILD_WITH_BCMTOOLS)
        add_definitions(-U__BLOCKS__) # work around for BCMlib's Block.h header
    endif()
        find_library(COCOA Cocoa)
        if (NOT COCOA)
            message(FATAL_ERROR "Cocoa Framework not found")
        endif()
        target_link_libraries(hiveCore ${COCOA})
endif()


# For test
add_executable (hiveCoreSimpleTest test/simpletest.cpp)
add_sanitizers (hiveCoreSimpleTest)
IF(HIVE_BUILD_WITH_PMLIB)
target_link_libraries (hiveCoreSimpleTest hiveCore ${PMLIB_LIBS})
ELSE()
target_link_libraries (hiveCoreSimpleTest hiveCore)
ENDIF()
# For test
add_executable (hiveCoreSolverSample test/solversample.cpp)
add_sanitizers (hiveCoreSolverSample)
IF(HIVE_BUILD_WITH_PMLIB)
target_link_libraries (hiveCoreSolverSample hiveCore ${PMLIB_LIBS})
ELSE()
target_link_libraries (hiveCoreSolverSample hiveCore)
ENDIF()
