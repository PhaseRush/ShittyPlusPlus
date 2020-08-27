#ifndef BENCH_TEST_CPP_BENCHMARK_H
#define BENCH_TEST_CPP_BENCHMARK_H

#include <functional>
#include <chrono>
#include "QualityOfLife.h"
#include "BenchmarkResult.h"

using namespace numbers;

class Benchmark {
private:
    virtual ull function(ull N) = 0;

    bool hasRun = false;
    ull N;
    BenchmarkResult *result{};

public:
    Benchmark(ull N) : N(N) {}

    void runBenchmark() {
        if (!hasRun) {
            const auto tic = std::chrono::steady_clock::now();
            const ull res = function(N);
            const auto toc = std::chrono::steady_clock::now();
            auto tempResult = BenchmarkResult(res, toc - tic);
            result = &tempResult;
            hasRun = true;
        }
    }

    BenchmarkResult *getResult() {
        if (!hasRun) runBenchmark();
        return result;
    }

    [[nodiscard]] ull getN() const {
        return N;
    }

    virtual ~Benchmark() = default;
};

#endif //BENCH_TEST_CPP_BENCHMARK_H