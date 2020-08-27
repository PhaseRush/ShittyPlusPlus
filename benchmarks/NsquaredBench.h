#include "../headers/Benchmark.h"

class NsquaredBench : public Benchmark {
private:
    ull function(ull N) override {
        ull acc = 0;
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
    NsquaredBench(const ull N) : Benchmark(N) {

    }
};