#include "../headers/Benchmark.h"

class LognBench : public Benchmark {
private:
    uint64_t function(uint64_t N) override {
        uint64_t acc = 0;
        for (int i = 1; i < N; i *= 2) {
            ++acc;
        }

        return acc;
    }

    std::string getName() override {
        return "LogN";
    }

public:
    LognBench(const uint64_t N) : Benchmark(N) {

    }
};