cmake_minimum_required(VERSION 3.16)
project(bench_test_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(bench_test_cpp main.cpp headers/BenchmarkResult.h headers/QualityOfLife.h headers/Benchmark.h benchmarks/ConstantBench.cpp benchmarks/LognBench.cpp benchmarks/LinearBench.cpp benchmarks/NlognBench.cpp benchmarks/NsquaredBench.cpp benchmarks/NsquaredTriangularBench.cpp)