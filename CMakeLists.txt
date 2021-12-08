cmake_minimum_required(VERSION 3.9)
project(python_interpreter)
set(CMAKE_CXX_STANDARD 17)

include_directories(file_types)

add_executable(python_interpreter main.cpp
        file_types/double.cpp
        file_types/int.cpp
        file_types/pyobject.cpp
        file_types/bool.cpp
        file_types/str.cpp
        file_types/list.cpp
        file_types/pyfunction.cpp
        file_types/pycodeobject.cpp
        file_types/builtins.cpp
        file_types/type_funcs.cpp
        file_types/iterator.cpp
        interpreter.cpp
        frame.cpp
        )

