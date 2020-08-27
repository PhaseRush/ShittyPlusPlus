#include "../headers/Benchmark.h"

class NlognBench : public Benchmark {
private:
    uint64_t function(uint64_t N) override {
        uint64_t acc = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < N; j *= 2) {
                ++acc;
            }
        }
        return acc;
    }

    std::string getName() override {
        return "N logN";
    }

public:
    NlognBench(const uint64_t N) : Benchmark(N) {

    }
};