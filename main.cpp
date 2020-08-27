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
        std::cout << std::setw(25) << benchmark->getName()// << "|"
                  << std::setw(10) << "N = " << benchmark->getN()// << "|"
                  << std::setw(20) << "Result = " << result.numericResult// << "|"
                  << std::setw(20) << "Time = " << benchmark->getResult().duration.count() << "s" << "\n";
    }

    return 0;
}
