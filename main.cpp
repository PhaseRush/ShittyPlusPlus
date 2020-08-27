#include <iostream>
#include <map>
#include <string>
#include <memory>

#include "headers/BenchmarkResult.h"
#include "headers/Benchmark.h"
#include "benchmarks/ConstantBench.cpp"
#include "benchmarks/LognBench.cpp"
#include "benchmarks/LinearBench.cpp"
#include "benchmarks/NlognBench.cpp"
#include "benchmarks/NsquaredBench.cpp"
#include "benchmarks/NsquaredTriangularBench.cpp"

std::vector<std::unique_ptr<Benchmark>> benches(const ull N) {
    std::vector<std::unique_ptr<Benchmark>> functions;
    functions.push_back(std::make_unique<ConstantBench>(N));
    functions.push_back(std::make_unique<LognBench>(N));
    functions.push_back(std::make_unique<LinearBench>(N));
    functions.push_back(std::make_unique<NlognBench>(N));
    functions.push_back(std::make_unique<NsquaredBench>(N));
    functions.push_back(std::make_unique<NsquaredTriangularBench>(N));
    return functions;
}

int main() {
    const ull N = 2ull << 10ull;
    const std::vector<std::unique_ptr<Benchmark>> benchmarks = benches(N);
    for (auto &benchmark : benchmarks) {
        auto result = benchmark->getResult();
        std::cout << benchmark->getName() << "\t"
                  << "N = " << benchmark->getN() << "\t"
                  << "Result = " << result.getNumericResult() << "\t"
                  << "Time = " << benchmark->getResult().getDuration().count() << "s" << "\n";
    }

    return 0;
}
