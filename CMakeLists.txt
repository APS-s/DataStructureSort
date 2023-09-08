cmake_minimum_required(VERSION 3.26)
project(DataStructureSort C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructureSort
        io/github/APS/main.c
        io/github/APS/bubble.c
        io/github/APS/quick.h
        io/github/APS/quick.c
        io/github/APS/heap.h
        io/github/APS/heap.c)
