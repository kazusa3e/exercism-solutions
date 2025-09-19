#include "rna_transcription.h"
#include <algorithm>

namespace rna_transcription {

char to_rna(char s) {
    if (s == 'G') return 'C';
    if (s == 'C') return 'G';
    if (s == 'T') return 'A';
    if (s == 'A') return 'U';
    return {};
}

std::string to_rna(const std::string &s) {
    std::string ret = s;
    std::transform(ret.begin(), ret.end(), ret.begin(), [](const auto &ch) {
        return to_rna(ch);
    });
    return ret;
}

}  // namespace rna_transcription
