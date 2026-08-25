cmake_minimum_required(VERSION 4.1)
project(trabalho_do_thiago C)

set(CMAKE_C_STANDARD 11)

include_directories(agenda)

add_executable(trabalho_do_thiago
        agenda/linkedlist.h
        agenda/main.c
        agenda/linkedlist.c)
