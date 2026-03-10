cmake_minimum_required(VERSION 3.10)
project(lab1)
add_executable(lab1 main.cpp ./src/matrix.cpp)
include_directories(
./
./src
./include
)