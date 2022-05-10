cmake_minimum_required(VERSION 3.5)

project(Graph LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS igraph.h listgraph.h matrixgraph.h)
set(SRC main.cpp listgraph.cpp matrixgraph.cpp)

add_executable(Graph ${SRC} ${HEADERS})