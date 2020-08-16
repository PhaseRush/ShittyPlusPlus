#include <iostream>
#include <limits.h>
#include <chrono>
#include <math.h>

using ull = unsigned long long;

ull linear(ull n) {
    ull acc = 0;
    for (ull i = 0; i < n; ++i) {
        ++acc;
    }
    return acc;
}

ull nlogn(ull n) {
    ull acc = 0;
    for (ull i = 0; i < n; ++i) {
        for (ull j = 1; j < n; j *= 2) {
            ++acc;
        }
    }
    return acc;
}

std::chrono::duration<double> runBench(ull N) {
    auto tic = std::chrono::steady_clock::now();
    const ull res = nlogn(N);
    auto toc = std::chrono::steady_clock::now();
    return toc - tic;
}

int main() {
//    const ull N = ULLONG_MAX / (2u << 16u);
    const ull N = 1000000;
    std::cout << "Running benchmark with N = " << N << '\n';

    auto tic = std::chrono::steady_clock::now();
    const ull res = nlogn(N);
    auto toc = std::chrono::steady_clock::now();

    std::cout << "Result = " << res << '\n';
    std::cout << (toc - tic).count() << "ms" << '\n';
    return 0;
}