#include "secret_handshake.h"
#include <algorithm>
#include <string>
#include <vector>

namespace secret_handshake {

std::vector<std::string> commands(unsigned c) {
    std::vector<std::string> ret;
    if (c & 0b0000'0001) ret.push_back("wink");
    if (c & 0b0000'0010) ret.push_back("double blink");
    if (c & 0b0000'0100) ret.push_back("close your eyes");
    if (c & 0b0000'1000) ret.push_back("jump");
    if (c & 0b0001'0000) std::reverse(ret.begin(), ret.end());
    return ret;
}

}  // namespace secret_handshake
