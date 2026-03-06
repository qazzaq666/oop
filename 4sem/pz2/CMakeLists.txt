cmake_minimum_required(VERSION 3.20) 
project(pz2)
add_executable(pz2 ./main.cpp ./src/triangle.cpp)

include_directories(
    ./
    ./src
)