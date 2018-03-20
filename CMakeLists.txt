cmake_minimum_required(VERSION 3.6)
project(TareaCorta)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp PagedArray.cpp prueba.cpp prueba.h Prueba1.cpp Prueba1.h)
add_executable(TareaCorta ${SOURCE_FILES})