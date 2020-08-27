#include "../headers/Benchmark.h"

class NlognBench : public Benchmark {
private:
    ull function(ull N) override {
        ull acc = 0;
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
    NlognBench(const ull N) : Benchmark(N) {

    }
};