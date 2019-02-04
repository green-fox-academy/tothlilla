cmake_minimum_required(VERSION 3.13)
project(ExBefInheritance)

set(CMAKE_CXX_STANDARD 14)

add_executable(ExBefInheritance main.cpp person.cpp person.h student.cpp student.h mentor.cpp mentor.h sponsor.cpp sponsor.h gender.cpp gender.h)