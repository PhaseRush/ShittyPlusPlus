#include <iostream>
#include <chrono>
#include <map>
#include <string>
#include <functional>

#include "headers/BenchmarkResult.h"

std::map<std::string, std::function<ull(ull)>> initFunctions();

[[maybe_unused]] ull linear(const ull n) {
    ull acc = 0;
    for (ull i = 0; i < n; ++i) {
        ++acc;
    }
    return acc;
}

[[maybe_unused]] ull nlogn(const ull n) {
    ull acc = 0;
    for (ull i = 0; i < n; ++i) {
        for (ull j = 1; j < n; j *= 2) {
            ++acc;
        }
    }
    return acc;
}

BenchmarkResult runBench(const ull N, const auto func) {
    const auto tic = std::chrono::steady_clock::now();
    const ull res = func(N);
    const auto toc = std::chrono::steady_clock::now();
    return BenchmarkResult(N, res, toc - tic);
}

int main() {
    const ull N = 2ull << 25ull;
    const std::map<std::string, std::function<ull(ull)>> functions = initFunctions();
    for (auto const&[name, function] : functions) {
        const BenchmarkResult bench = runBench(N, function);
        std::cout << "Running Function: " << name << "\n"
                  << "N = " << N
                  << "\tResult = " << bench.getResult() << "\t"
                  << bench.getDuration().count() << "s" << '\n';
    }

    return 0;
}

std::map<std::string, std::function<ull(ull)>> initFunctions() {
    std::map<std::string, std::function<ull(ull)>> functions;
    functions.emplace("linear", linear);
    functions.emplace("nlogn", nlogn);
    return functions;
}
