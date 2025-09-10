#include "raindrops.h"
#include <string>

namespace raindrops {

std::string convert(unsigned n) {

    std::string ret;

    if (n % 3 == 0) ret += "Pling";
    if (n % 5 == 0) ret += "Plang";
    if (n % 7 == 0) ret += "Plong";

    return (ret.empty()) ? std::to_string(n) : ret;
}

}  // namespace raindrops
