#include "../headers/Benchmark.h"

class ConstantBench : public Benchmark {
private:
    uint64_t function(uint64_t N) override {
        return 1;
    }

    std::string getName() override {
        return "Constant";
    }

public:
    ConstantBench(const uint64_t N) : Benchmark(N) {

    }
};