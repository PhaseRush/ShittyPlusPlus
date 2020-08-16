#include "headers/BenchmarkResult.h"

BenchmarkResult::BenchmarkResult(ull N, ull result, std::chrono::duration<double> duration) {
    this->N = N;
    this->result = result;
    this->duration = duration;
}
