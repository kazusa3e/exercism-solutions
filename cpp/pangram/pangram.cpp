#include "pangram.h"
#include <cctype>
#include <vector>

namespace pangram {

bool is_pangram(const std::string &s) {
    std::vector<bool> bitmap(26, false);
    for (const auto &ch : s) {
        if (!std::isalpha(ch)) continue;
        char c = std::tolower(ch);
        bitmap[c - 'a'] = true;
    }
    return std::all_of(bitmap.cbegin(), bitmap.cend(), [](const auto &b) {
        return b;
    });
}

}  // namespace pangram
