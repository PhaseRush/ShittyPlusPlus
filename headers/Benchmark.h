#ifndef BENCH_TEST_CPP_BENCHMARK_H
#define BENCH_TEST_CPP_BENCHMARK_H

#include <functional>
#include <chrono>
#include "QualityOfLife.h"

using namespace numbers;


class Benchmark {
public:
    struct Result {
        ull numericResult;
        std::chrono::duration<double> duration;
    };

private:
    virtual ull function(ull N) = 0;

    bool hasRun = false;
    ull N;
    Result result;

public:
    Benchmark(ull N) : N(N) {}

    virtual std::string getName() = 0;

    void runBenchmark() {
        if (!hasRun) {
            const auto tic = std::chrono::steady_clock::now();
            const ull res = function(N);
            const auto toc = std::chrono::steady_clock::now();
            result = Result();
            result.numericResult = res;
            result.duration = toc - tic;
            hasRun = true;
        }
    }

    const Result &getResult() {
        if (!hasRun) runBenchmark();
        return result;
    }

    [[nodiscard]] ull getN() const {
        return N;
    }

    virtual ~Benchmark() = default;
};

#endif //BENCH_TEST_CPP_BENCHMARK_H
