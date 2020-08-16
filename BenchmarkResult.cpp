#include "headers/BenchmarkResult.h"

BenchmarkResult::BenchmarkResult(ull N, ull result, std::chrono::duration<double> duration) {
    this->N = N;
    this->result = result;
    this->duration = duration;
}


ull BenchmarkResult::getN() const {
    return this->N;
}

ull BenchmarkResult::getResult() const {
    return this->result;
}

std::chrono::duration<double> BenchmarkResult::getDuration() const {
    return this->duration;
}


