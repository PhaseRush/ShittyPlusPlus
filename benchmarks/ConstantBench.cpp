#include "../headers/Benchmark.h"

class ConstantBench : public Benchmark {
private:
    ull function(ull N) override {
        return 1;
    }

public:
    ConstantBench(const ull N) : Benchmark(N) {

    }
};