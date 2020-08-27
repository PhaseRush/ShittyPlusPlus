cmake_minimum_required(VERSION 3.16)
project(bench_test_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(bench_test_cpp main.cpp headers/QualityOfLife.h headers/Benchmark.h benchmarks/ConstantBench.h benchmarks/LognBench.h benchmarks/LinearBench.h benchmarks/NlognBench.h benchmarks/NsquaredBench.h benchmarks/NsquaredTriangularBench.h)