cmake_minimum_required(VERSION 3.10)
project(bench_test_cpp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_RELEASE "-O0")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(bench_test_cpp main.cpp headers/Benchmark.h benchmarks/ConstantBench.h benchmarks/LognBench.h benchmarks/LinearBench.h benchmarks/NlognBench.h benchmarks/NsquaredBench.h benchmarks/NsquaredTriangularBench.h benchmarks/IteratedLogarithmic.h benchmarks/PolyLogarithmic.h benchmarks/SubExponential.h benchmarks/Exponential.h benchmarks/Factorial.h)