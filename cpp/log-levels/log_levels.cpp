#include <algorithm>
#include <cstddef>
#include <sstream>
#include <string>

namespace log_line {
std::string message(std::string line) {
    const auto pos = line.find(' ');
    line.erase(0, pos + 1);
    return line;
}

std::string log_level(std::string line) {
    const auto e = line.find("]") + line.begin();
    std::copy_backward(line.begin() + 1, e, e - 1);
    line.erase(e - line.begin() - 1);
    return line;
}

std::string reformat(std::string line) {
    const auto level = log_level(line);
    const auto msg = message(line);
    std::ostringstream oss;
    oss << msg << " (" << level << ")";
    return oss.str();
}
}  // namespace log_line
