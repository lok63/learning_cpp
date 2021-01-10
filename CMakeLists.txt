cmake_minimum_required(VERSION 3.17)
project(learning_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(learning_cpp main.cpp InclusionGuardCar/car.cpp InclusionGuardCar/car.h InclusionGuardCar/engine.cpp InclusionGuardCar/engine.h matrix/matrix.cpp matrix/matrix.h)