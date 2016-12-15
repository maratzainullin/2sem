cmake_minimum_required(VERSION 2.8)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(vector_tests vector_tests.cpp vector3d.cpp)

target_link_libraries(vector_tests ${GTEST_LIBRARIES})
