#ifndef BENCH_TEST_CPP_BENCHMARKRESULT_H
#define BENCH_TEST_CPP_BENCHMARKRESULT_H

#include "QualityOfLife.h"

using namespace phaserush;

class BenchmarkResult {
private:
    ull N, result;
    std::chrono::duration<double> duration{};
public:
    BenchmarkResult(ull N, ull result, std::chrono::duration<double> duration);
};


#endif //BENCH_TEST_CPP_BENCHMARKRESULT_H
