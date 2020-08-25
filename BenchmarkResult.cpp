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

std::function<ull(ull)> BenchmarkResult::getFunction() const {
    return this->function;
}

std::chrono::duration<double> BenchmarkResult::getDuration() const {
    return this->duration;
}

