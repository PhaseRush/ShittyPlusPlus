cmake_minimum_required(VERSION 3.16)
project(bench_test_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(bench_test_cpp main.cpp BenchmarkResult.cpp headers/BenchmarkResult.h headers/QualityOfLife.h)