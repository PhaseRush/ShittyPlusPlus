#include "../headers/Benchmark.h"

class NsquaredBench : public Benchmark {
private:
    uint64_t function(uint64_t N) override {
        uint64_t acc = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ++acc;
            }
        }
        return acc;
    }

    std::string getName() override {
        return "N Squared";
    }

public:
    NsquaredBench(const uint64_t N) : Benchmark(N) {

    }
};