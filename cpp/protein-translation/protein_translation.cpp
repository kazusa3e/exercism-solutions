#include "protein_translation.h"
#include <string>
#include <unordered_map>
#include <vector>

namespace protein_translation {

static std::unordered_map<std::string, std::string> codon_map = {
    {"AUG", "Methionine"},
    {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"}, {"UUG", "Leucine"},
    {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
    {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
    {"UGU", "Cysteine"}, {"UGC", "Cysteine"},
    {"UGG", "Tryptophan"},
    {"UAA", ""}, {"UAG", ""}, {"UGA", ""},
};

std::vector<std::string> proteins(const std::string &rna) {


    std::vector<std::string> ret;
    for (auto iter = rna.cbegin(); iter != rna.cend(); iter += 3) {
        if (std::distance(iter, rna.cend()) < 3) break;
        const auto cod = std::string {*iter, *(iter + 1), *(iter + 2)};
        const auto am = codon_map[cod];
        if (am.empty()) break;
        ret.push_back(am);
    }
    return ret;
}

}  // namespace protein_translation
