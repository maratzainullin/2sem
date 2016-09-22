cmake_minimum_required(VERSION 3.6)
project(2sem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES0 draft.cpp)
set(SOURCE_FILES1 sem3_ex1.cpp)
set(SOURCE_FILES2 sem3_ex2.cpp)
set(SOURCE_FILES3 sem3_ex3.cpp)
set(SOURCE_FILES4 sem3_ex4.cpp)
set(SOURCE_FILES5 sem4_ex1.cpp)

add_executable(draft ${SOURCE_FILES0})
add_executable(task1 ${SOURCE_FILES1})
add_executable(task2 ${SOURCE_FILES2})
add_executable(task3 ${SOURCE_FILES3})
add_executable(task4 ${SOURCE_FILES4})
add_executable(task5 ${SOURCE_FILES5})

