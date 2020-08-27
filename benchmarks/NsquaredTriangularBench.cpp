#include "../headers/Benchmark.h"

class NsquaredTriangularBench : public Benchmark {
private:
    ull function(ull N) override {
        ull acc = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                ++acc;
            }
        }
        return acc;
    }

    std::string getName() override {
        return "N Squared - Triangular";
    }

public:
    NsquaredTriangularBench(const ull N) : Benchmark(N) {

    }
};