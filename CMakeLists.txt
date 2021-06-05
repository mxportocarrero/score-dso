cmake_minimum_required(VERSION 2.8)
project(SCOREdso)

# C++ standard
if(${CMAKE_VERSION} VERSION_LESS "3.2.0")
  set( CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}" )
else()
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

# custom modules
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# TODO: change this to not output outside build dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# required libs
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Glog REQUIRED)
find_package(Pangolin REQUIRED)

# optional libs
find_package(LibZip QUIET)

set(CMAKE_CXX_FLAGS "-Wall -Wno-deprecated -march=native -Wno-ignored-qualifiers -Wno-reorder -Wno-missing-braces")

if(NOT APPLE)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

# including private directories

include_directories(
        ${EIGEN3_INCLUDE_DIR}
        ${OpenCV_INCLUDE_DIR}
        ${Glog_INCLUDE_DIRS}
        ${Pangolin_INCLUDE_DIRS}

        ${PROJECT_SOURCE_DIR}/include
        # ${PROJECT_SOURCE_DIR}/thirdparty/
        # ${PROJECT_SOURCE_DIR}/thirdparty/g2o/
        # ${PROJECT_SOURCE_DIR}/thirdparty/DBoW3/
)

set( THIRD_PARTY_LIBS
        ${OpenCV_LIBS}
        ${GLOG_LIBRARY}
        ${Pangolin_LIBRARIES}
        # ${PROJECT_SOURCE_DIR}/thirdparty/g2o/lib/libg2o${CMAKE_SHARED_LIBRARY_SUFFIX}
        # ${PROJECT_SOURCE_DIR}/thirdparty/DBoW3/build/src/libDBoW3${CMAKE_SHARED_LIBRARY_SUFFIX}
        ${LIBZIP_LIBRARY}
)

add_subdirectory(src)
add_subdirectory(apps)