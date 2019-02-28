cmake_minimum_required(VERSION 3.13)
project(Ex_01_create_linked_list C)

set(CMAKE_C_STANDARD 99)

add_executable(Ex_01_create_linked_list main.c linked_list.h linked_list.c)