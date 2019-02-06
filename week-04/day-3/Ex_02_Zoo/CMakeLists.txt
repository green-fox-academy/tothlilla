cmake_minimum_required(VERSION 3.13)
project(Ex_02_Zoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ex_02_Zoo main.cpp animal.cpp animal.h mammals.cpp mammals.h byegg.cpp byegg.h bird.cpp bird.h reptile.cpp reptile.h)