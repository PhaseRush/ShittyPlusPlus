#include <iostream>
#include <limits.h>
#include <chrono>
#include <math.h>

#include "headers/BenchmarkResult.h"

using ull = unsigned long long;

ull linear(ull n) {
    ull acc = 0;
    for (ull i = 0; i < n; ++i) {
        ++acc;
    }
    return acc;
}

ull nlogn(ull n) {
    ull acc = 0;
    for (ull i = 0; i < n; ++i) {
        for (ull j = 1; j < n; j *= 2) {
            ++acc;
        }
    }
    return acc;
}

BenchmarkResult runBench(ull N, auto func) {
    auto tic = std::chrono::steady_clock::now();
    const ull res = func(N);
    auto toc = std::chrono::steady_clock::now();
    return BenchmarkResult(N, res, toc - tic);
}

int main() {
//    const ull N = ULLONG_MAX / (2u << 16u);
    const ull N = 1000000;
    std::cout << "Running benchmark with N = " << N << '\n';

    const BenchmarkResult bench = runBench(N, linear);

    std::cout << "Result = " << bench.getResult() << '\n';
    std::cout << bench.getDuration().count() << "ms" << '\n';
    return 0;
}