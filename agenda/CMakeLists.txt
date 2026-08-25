cmake_minimum_required(VERSION 3.28.3)
project(agenda C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(agenda
        linkedlist.h
        main.c
        linkedlist.c)
