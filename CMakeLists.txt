cmake_minimum_required(VERSION 3.21)
project(student_management)

set(CMAKE_CXX_STANDARD 17)

add_executable(student_management main.cpp Student.cpp Student.h StudentManager.cpp StudentManager.h Menu.cpp Menu.h)
