#include "nucleotide_count.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

namespace nucleotide_count {

std::map<char, int> count(const std::string &s) {
    const std::vector<char> validNucleotide = { 'A', 'C', 'G', 'T' };
    std::map<char, int> ret = {
        { 'A', 0 },
        { 'C', 0 },
        { 'G', 0 },
        { 'T', 0 },
    };
    for (const auto &ch : s) {
        if (const auto pos = std::find(validNucleotide.cbegin(), validNucleotide.cend(), ch); pos == validNucleotide.cend()) {
            throw std::invalid_argument{ "" };
        }

        auto &bucket = ret[ch];
        ++bucket;
    }
    return ret;
}

}  // namespace nucleotide_count
