cmake_minimum_required(VERSION 3.6)
project(2sem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES0 draft.cpp dynlist.cpp)
set(SOURCE_FILES1 sem5_ex1.cpp)

add_executable(draft ${SOURCE_FILES0})
add_executable(task1 sem3_ex1.cpp)
add_executable(task2 sem3_ex2.cpp)
add_executable(task3 sem3_ex3.cpp)
add_executable(task4 sem3_ex4.cpp)
add_executable(task5 sem4_ex1.cpp dynlist.cpp)
add_executable(task6 ${SOURCE_FILES1})





