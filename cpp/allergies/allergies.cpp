#include "allergies.h"

namespace allergies {

allergy_test::allergy_test(unsigned int n) {
    if (n & 0b0000'0001) allergies_.emplace("eggs");
    if (n & 0b0000'0010) allergies_.emplace("peanuts");
    if (n & 0b0000'0100) allergies_.emplace("shellfish");
    if (n & 0b0000'1000) allergies_.emplace("strawberries");
    if (n & 0b0001'0000) allergies_.emplace("tomatoes");
    if (n & 0b0010'0000) allergies_.emplace("chocolate");
    if (n & 0b0100'0000) allergies_.emplace("pollen");
    if (n & 0b1000'0000) allergies_.emplace("cats");
}

bool allergy_test::is_allergic_to(const std::string &a) const {
    return (allergies_.find(a) != allergies_.end());
}

}  // namespace allergies
