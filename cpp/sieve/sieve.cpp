#include "sieve.h"
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>

namespace sieve {

std::vector<int> primes(unsigned n) {
    if (n < 2) return {};
    std::vector<int> ret(n - 1);
    std::iota(ret.begin(), ret.end(), 2);
    auto begin = ret.begin() + 1;
    for (auto i = 2ull; i <= n; ++i) {
        if (begin == ret.end()) break;
        const auto pos = std::copy_if(begin, ret.end(), begin, [i](const auto &v) {
            return (v % i) != 0;
        });
        ret.erase(pos, ret.end());
        ++begin;
    }
    return ret;
}

}  // namespace sieve
