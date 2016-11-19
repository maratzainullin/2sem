cmake_minimum_required(VERSION 3.6)

project(2sem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")




add_executable(draftEx draft.cpp)
#add_executable(task1 Tasks/sem3_ex1.cpp)
#add_executable(task2 Tasks/sem3_ex2.cpp)
#add_executable(task3 Tasks/sem3_ex3.cpp)
#add_executable(task4 Tasks/sem3_ex4.cpp)


add_executable(DinListEx     DinList/dynlist.cpp Data/data.cpp Data/data.h DinList/dynlist_test.cpp)



add_executable(HashTableEx   HashTable/hash_table.cpp DinList/dynlist.cpp Data/data.cpp Data/data.h HashTable/hash.h)
add_executable(DimQEx        DimQ.cpp TypeIdFix/type.cpp TypeIdFix/type.h)




