#include <iostream>
#include <map>
#include <string>

#include "headers/BenchmarkResult.h"
#include "headers/Benchmark.h"
#include "benchmarks/ConstantBench.cpp"

std::map<std::string, Benchmark> getBenchmarks(const ull N) {
    std::map<std::string, Benchmark> functions;
    functions.emplace("placeholder words", new ConstantBench(N));
    return functions;
}

int main() {
    const ull N = 2ull << 20ull;
    const std::map<std::string, Benchmark> benchmarks = getBenchmarks(N);
    for (auto const&[placeholder, benchmark] : benchmarks) {
        auto result = benchmark.getResult();
        std::cout << placeholder << "\t"
                  << benchmark.getN() << "\n"
                  << result->getNumericResult();
    }

    return 0;
}
