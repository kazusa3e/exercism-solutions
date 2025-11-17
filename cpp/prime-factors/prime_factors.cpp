#include "prime_factors.h"
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

namespace prime_factors {

auto of(long long x) -> std::vector<long long> {
    const auto is_prime = [](unsigned long long x) -> bool {
        if (x < 2) return false;
        bool flag = true;
        for (auto i = 3ull; i < std::floor(std::sqrt(x)); ++i) {
            if (x % i == 0) {
                flag = false;
                break;
            }
        }
        return flag;
    };

    if (x < 2) return {};
    if (x == 2) return {2};

    auto i = 2ll;
    while (i < x) {
        if (is_prime(i) && (x % i == 0)) break;
        ++i;
    }

    if (i == x) return {x};

    const auto recur = of(x / i);
    auto ret = std::vector<long long> {i};
    std::move(recur.begin(), recur.end(), std::back_inserter(ret));
    return ret;
}

}  // namespace prime_factors
