#ifndef BENCH_TEST_CPP_BENCHMARKRESULT_H
#define BENCH_TEST_CPP_BENCHMARKRESULT_H

#include "QualityOfLife.h"
#include <chrono>
#include <functional>

using namespace myMath;

class BenchmarkResult {
private:
    ull N, result;
    std::function<ull(ull)> function;
    std::chrono::duration<double> duration{};
public:
    BenchmarkResult(ull N, ull result, std::chrono::duration<double> duration);

    [[nodiscard]] ull getN() const;

    [[nodiscard]] ull getResult() const;

    [[nodiscard]] std::function<ull(ull)> getFunction() const;

    [[nodiscard]] std::chrono::duration<double> getDuration() const;
};


#endif //BENCH_TEST_CPP_BENCHMARKRESULT_H
