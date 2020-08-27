#ifndef BENCH_TEST_CPP_BENCHMARKRESULT_H
#define BENCH_TEST_CPP_BENCHMARKRESULT_H

#include "QualityOfLife.h"
#include <chrono>
#include <functional>

using namespace numbers;

class BenchmarkResult {
private:
    ull numericResult;
    std::chrono::duration<double> duration{};
public:
    BenchmarkResult(ull result, std::chrono::duration<double> duration) :
            numericResult(result), duration(duration) {};

    [[nodiscard]] ull getNumericResult() const {
        return numericResult;
    }

    [[nodiscard]] std::chrono::duration<double> getDuration() const {
        return duration;
    }
};


#endif //BENCH_TEST_CPP_BENCHMARKRESULT_H
