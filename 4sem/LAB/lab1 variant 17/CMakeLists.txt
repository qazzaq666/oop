cmake_minimum_required(VERSION 3.20) 
project(lab1)
add_executable(lab1 ../src/matrix.cpp ../main.cpp)
include_directories(
    ./
    ./src
    ./include
)