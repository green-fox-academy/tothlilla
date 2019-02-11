cmake_minimum_required(VERSION 3.13)
project(ExampleExam_Shelter)

set(CMAKE_CXX_STANDARD 14)

add_executable(ExampleExam_Shelter main.cpp animalshelter.cpp animalshelter.h animal.cpp animal.h dog.cpp dog.h cat.cpp cat.h parrot.cpp parrot.h)