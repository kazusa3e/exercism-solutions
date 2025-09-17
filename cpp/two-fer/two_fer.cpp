#include "two_fer.h"

namespace two_fer {

std::string two_fer(const std::string &name) {
    if (name.empty()) {
        return "One for you, one for me.";
    } else {
        return std::string{} + "One for " + name + ", one for me.";
    }
}

}  // namespace two_fer
