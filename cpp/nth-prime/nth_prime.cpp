#include "nth_prime.h"
#include <cmath>
#include <stdexcept>

namespace nth_prime {

static bool is_prime(unsigned long long n) noexcept {
    if (n < 2) return false;
    for (auto i = 2ull; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

unsigned long long nth(unsigned n) {
    if (n == 0) throw std::domain_error{ "" };
    auto ret = 1ull;
    while (n--) {
        ++ret;
        while (!is_prime(ret)) ++ret;
    }
    return ret;
}

}  // namespace nth_prime
