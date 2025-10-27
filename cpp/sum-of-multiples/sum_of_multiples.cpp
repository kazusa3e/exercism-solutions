#include "sum_of_multiples.h"
#include <numeric>
#include <set>

namespace sum_of_multiples {

auto to(const std::vector<unsigned> &items, unsigned level) -> std::size_t {
    if (level == 0) return 0;
    std::set<std::size_t> scores;
    for (const auto &itm : items) {
        if (itm == 0) continue;
        for (unsigned ix = 0; ix < level; ix += itm) {
            scores.insert(ix);
        }
    }
    return std::accumulate(scores.cbegin(), scores.cend(), 0);
}

}  // namespace sum_of_multiples
