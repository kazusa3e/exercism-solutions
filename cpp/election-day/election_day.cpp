#include <algorithm>
#include <functional>
#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {

    ElectionResult() = default;
    ElectionResult(std::string &&_name, int _votes)
        : name(std::move(_name)), votes(_votes) {}

    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.
int vote_count(const ElectionResult &er) {
    return er.votes;
}

// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.
void increment_vote_count(ElectionResult &er, int num_votes) {
    er.votes += num_votes;
}

// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.
ElectionResult &determine_result(std::vector<ElectionResult> &ers) {
    const auto pos = std::max_element(ers.cbegin(), ers.cend(), [](const ElectionResult &lhs, const ElectionResult &rhs) {
        return std::less<>{}(lhs.votes, rhs.votes);
    });
    auto &ref = const_cast<ElectionResult &>(*pos);
    ref.name = "President " + ref.name;
    return ref;
}

}  // namespace election
