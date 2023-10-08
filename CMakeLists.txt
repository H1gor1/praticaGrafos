cmake_minimum_required(VERSION 3.22)
project(praticaGrafos C)

set(CMAKE_C_STANDARD 11)

add_executable(praticaGrafos main.c graphListAdj.h graphMatAdj.h graphListAdj.c graphMatAdj.c)
