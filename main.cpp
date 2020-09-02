#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <iomanip>

#include "headers/Benchmark.h"
#include "benchmarks/ConstantBench.h"
#include "benchmarks/LognBench.h"
#include "benchmarks/LinearBench.h"
#include "benchmarks/NlognBench.h"
#include "benchmarks/NsquaredBench.h"
#include "benchmarks/NsquaredTriangularBench.h"

std::vector<std::unique_ptr<Benchmark>> benches(const uint64_t N) {
    std::vector<std::unique_ptr<Benchmark>> functions;
    functions.push_back(std::make_unique<ConstantBench>(N));
    functions.push_back(std::make_unique<LognBench>(N));
    functions.push_back(std::make_unique<LinearBench>(N));
    functions.push_back(std::make_unique<NlognBench>(N));
    functions.push_back(std::make_unique<NsquaredTriangularBench>(N));
    functions.push_back(std::make_unique<NsquaredBench>(N));
    return functions;
}

int main() {
    const uint64_t N = 2ull << 30ull;
    const std::vector<std::unique_ptr<Benchmark>> benchmarks = benches(N);

    const int8_t nameWidth = 25, sizeWidth = 20, resultWidth = 30, timeWidth = 20;

    std::cout << std::left
              << std::setw(nameWidth) << "Name"
              << std::setw(sizeWidth) << "Input Size (N)"
              << std::setw(resultWidth) << "Numeric Result"
              << std::setw(timeWidth) << "Time (seconds)" << "\n";

    for (auto &benchmark : benchmarks) {
        auto result = benchmark->getResult();
        std::cout << std::setw(nameWidth) << benchmark->getName()
                  << std::setw(sizeWidth) << benchmark->getN()
                  << std::setw(resultWidth) << result.numericResult
                  << std::setw(timeWidth) << benchmark->getResult().duration.count() << "\n";
    }

    return 0;
}
