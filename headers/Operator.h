#ifndef BENCH_TEST_CPP_OPERATOR_H
#define BENCH_TEST_CPP_OPERATOR_H

#include <string>

class Operator {
private:

public:
    Operator() = default;

    virtual std::string getName() = 0;

    virtual uint64_t initial() = 0;

    virtual ~Operator() = default;
};

#endif //BENCH_TEST_CPP_OPERATOR_H
