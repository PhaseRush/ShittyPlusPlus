#include "../headers/Benchmark.h"

class ConstantBench : public Benchmark {
private:
    ull function(ull N) override {
        return 1;
    }

    std::string getName() override {
        return "Constant";
    }

public:
    ConstantBench(const ull N) : Benchmark(N) {

    }
};