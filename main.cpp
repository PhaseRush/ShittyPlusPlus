#include <iostream>
#include <chrono>
#include <map>
#include <string>
#include <functional>

#include "headers/BenchmarkResult.h"

std::map<std::string, std::function<ull(ull)>> initFunctions();

ull constant([[maybe_unused]] const ull n) {
    return 1;
}

ull logn(const ull n) {
    ull acc = 0;
    for (ull i = 1; i < n; i *= 2) {
        ++acc;
    }
    return acc;
}

ull linear(const ull n) {
    ull acc = 0;
    for (ull i = 0; i < n; ++i) {
        ++acc;
    }
    return acc;
}

ull nlogn(const ull n) {
    ull acc = 0;
    for (ull i = 0; i < n; ++i) {
        for (ull j = 1; j < n; j *= 2) {
            ++acc;
        }
    }
    return acc;
}

ull nsquared_triangular(const ull n) {
    ull acc = 0;
    for (ull i = 0; i < n; ++i) {
        for (ull j = i; j < n; ++j) {
            ++acc;
        }
    }
    return acc;
}

ull nsquared(const ull n) {
    ull acc = 0;
    for (ull i = 0; i < n; ++i) {
        for (ull j = 0; j < n; ++j) {
            ++acc;
        }
//        if (i % 1000 == 0) std::cout << i << " ";
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
    const ull N = 2ull << 20ull;
    const std::map<std::string, std::function<ull(ull)>> functions = initFunctions();
    for (auto const&[name, function] : functions) {
        const BenchmarkResult bench = runBench(N, function);
        std::cout << "Running Function: " << name << "\n"
                  << "N = " << bench.getN() << "\t"
                  << "Result = " << bench.getResult() << "\t"
                  << bench.getDuration().count() << "s" << "\n";
    }

    return 0;
}

std::map<std::string, std::function<ull(ull)>> initFunctions() {
    std::map<std::string, std::function<ull(ull)>> functions;
    functions.emplace("constant", constant);
    functions.emplace("logn", logn);
    functions.emplace("linear", linear);
    functions.emplace("nlogn", nlogn);
    functions.emplace("nsquared_triangular", nsquared_triangular);
//    functions.emplace("nsquared", nsquared);
    return functions;
}
