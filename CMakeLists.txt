cmake_minimum_required(VERSION 3.9)
project(python_interpreter)
set(CMAKE_CXX_STANDARD 17)

add_executable(python_interpreter main.cpp file_types/double.cpp file_types/int.cpp file_types/pyobject.cpp file_types/bool.cpp file_types/str.cpp file_types/pyfunction.cpp)
