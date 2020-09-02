#ifndef BENCH_TEST_CPP_BENCHMARK_H
#define BENCH_TEST_CPP_BENCHMARK_H

#include <functional>
#include <chrono>

class Benchmark {
public:
    struct Result {
        uint64_t numericResult;
        std::chrono::duration<double> duration;
    };

private:
    virtual uint64_t function(uint64_t N) = 0;

    bool hasRun = false;
    uint64_t N;
    Result result;

public:
    Benchmark(uint64_t N) : N(N) {}

    virtual std::string getName() = 0;

    void runBenchmark() {
        if (!hasRun) {
            const auto tic = std::chrono::steady_clock::now();
            const uint64_t res = function(N);
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

    [[nodiscard]] uint64_t getN() const {
        return N;
    }

    virtual ~Benchmark() = default;
};

#endif //BENCH_TEST_CPP_BENCHMARK_H
