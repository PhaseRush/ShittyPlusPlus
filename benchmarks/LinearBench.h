#include "../headers/Benchmark.h"

class LinearBench : public Benchmark {
private:
    uint64_t function(uint64_t N) override {
        uint64_t acc = 0;
        for (int i = 0; i < N; ++i) {
            ++acc;
        }
        return acc;
    }

    std::string getName() override {
        return "Linear";
    }

public:
    LinearBench(const uint64_t N) : Benchmark(N) {

    }
};