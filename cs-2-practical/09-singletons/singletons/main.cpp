#include <iostream>

class Random {
public:
    Random(const Random &) = delete;

    static Random &get() {
        static Random instance;
        return instance;
    }

    static float genFloat() {
        return get().iFloat();
    }

private:
    float iFloat() { return randomGenerator; }

    float randomGenerator = 0.5f;

    Random() = default;

    static Random sInstance;
};

namespace RandomNamespace {
    static float randomGenerator = 0.05f;
    static float genFloat() {
        return randomGenerator;
    }
}

int main() {
    float number = Random::genFloat();
    std::cout << number << std::endl;
    std::cout<<RandomNamespace::genFloat()<<std::endl;
    return 0;
}
