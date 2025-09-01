#include <algorithm>
#include <array>
#include <functional>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> ret;
    std::copy(student_scores.cbegin(), student_scores.cend(), std::back_inserter(ret));
    return ret;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    return std::count_if(student_scores.cbegin(), student_scores.cend(), [](const auto &score) {
        return score <= 40;
    });
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    const auto gap = (highest_score - 40) / 4;
    return {
        41,
        41 + gap * 1,
        41 + gap * 2,
        41 + gap * 3,
    };
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::pair<int, std::string>> pairs;
    for (auto ix = 0ull; ix != student_scores.size(); ++ix) {
        pairs.push_back(std::make_pair(student_scores[ix], student_names[ix]));
    }
    std::sort(pairs.begin(), pairs.end(), std::greater<> {});
    std::vector<std::string> ret;
    for (auto ix = 0ull; ix != pairs.size(); ++ix) {
        const auto s = std::to_string(ix + 1) + ". " + pairs[ix].second + ": " + std::to_string(pairs[ix].first);
        ret.push_back(std::move(s));
    }
    return ret;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    const auto pos = std::find(student_scores.cbegin(), student_scores.cend(), 100);
    if (pos == student_scores.cend()) return "";
    return *(student_names.begin() + (pos - student_scores.cbegin()));
}
