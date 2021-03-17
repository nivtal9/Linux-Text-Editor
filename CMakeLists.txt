cmake_minimum_required(VERSION 3.17)
project(editor)

set(CMAKE_CXX_STANDARD 14)

add_executable(editor main.cpp Editor.cpp Editor.h Document.cpp Document.h)