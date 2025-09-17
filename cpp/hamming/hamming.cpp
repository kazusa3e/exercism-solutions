#include "hamming.h"
#include <cstddef>
#include <stdexcept>

namespace hamming {

std::size_t compute(const std::string &a, const std::string &b) {
    if (a.size() != b.size()) throw std::domain_error {""};
    std::size_t ret = 0;
    for (auto ix = 0ull; ix != a.size(); ++ix) {
        if (a[ix] != b[ix]) ++ret;
    }
    return ret;
}

}  // namespace hamming
