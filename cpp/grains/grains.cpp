#include "grains.h"
#include <cmath>

namespace grains {

unsigned long long square(unsigned n) {
    return std::pow(2, n - 1);
}

unsigned long long total() {
    unsigned long long acc = 0;
    for (auto ix = 1ull; ix <= 64; ++ix) {
        acc += square(ix);
    }
    return acc;
}

}  // namespace grains
