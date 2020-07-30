cmake_minimum_required(VERSION 3.16)
project(CRUD C)

set(CMAKE_C_STANDARD 11)

add_executable(CRUD src/main.c src/helpers.c headers/helpers.h src/student.c headers/student.h src/sorter.c headers/sorter.h)