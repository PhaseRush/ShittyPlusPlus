#include "../headers/Benchmark.h"

class LinearBench : public Benchmark {
private:
    ull function(ull N) override {
        ull acc = 0;
        for (int i = 0; i < N; ++i) {
            ++acc;
        }
        return acc;
    }

    std::string getName() override {
        return "Linear";
    }

public:
    LinearBench(const ull N) : Benchmark(N) {

    }
};