cmake_minimum_required(VERSION 3.15)
project(Digkstra)

set(CMAKE_CXX_STANDARD 14)

add_executable(Digkstra main.cpp Map.cpp Map.h node.cpp node.h)