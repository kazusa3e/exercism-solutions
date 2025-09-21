#pragma once

#include <string>
#include <unordered_set>
namespace allergies {

class allergy_test {
public:
    allergy_test() = delete;
    allergy_test(unsigned int n);
    bool is_allergic_to(const std::string &a) const;
    std::unordered_set<std::string> get_allergies() const {
        return allergies_;
    }

private:
    std::unordered_set<std::string> allergies_;
};

// std::unordered_set<std::string> allergy_test(unsigned n);

}  // namespace allergies
