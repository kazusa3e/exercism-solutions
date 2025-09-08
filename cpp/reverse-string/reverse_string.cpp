#include "reverse_string.h"
#include <algorithm>

namespace reverse_string {

std::string reverse_string(const std::string &s) {
    auto ret = s;
    std::reverse(ret.begin(), ret.end());
    return ret;
}

}  // namespace reverse_string
