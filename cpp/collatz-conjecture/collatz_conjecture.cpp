#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

unsigned long long steps(long long int s) {
    if (s <= 0) throw std::domain_error{ "" };
    unsigned long long ret = 0;
    while (s != 1) {
        s = (s % 2 == 0) ? s / 2 : s * 3 + 1;
        ++ret;
    }
    return ret;
}

}  // namespace collatz_conjecture
