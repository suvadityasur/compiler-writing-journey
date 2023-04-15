cmake_minimum_required(VERSION 3.25)
project(minicc C)

set(CMAKE_C_STANDARD 23)

add_executable(minicc main.c token.h scanner.c scanner.h common.h)
