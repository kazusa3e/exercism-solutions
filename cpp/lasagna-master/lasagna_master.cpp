#include "lasagna_master.h"
#include <algorithm>
#include <iterator>

namespace lasagna_master {

int preparationTime(const std::vector<std::string> &layers, int time_per_layer) {
    return layers.size() * time_per_layer;
}

amount quantities(const std::vector<std::string> &layers) {
    return amount{
        .noodles = static_cast<int>(std::count(layers.cbegin(), layers.cend(), "noodles") * noddle_quantity),
        .sauce = std::count(layers.cbegin(), layers.cend(), "sauce") * sauce_quantity,
    };
}

void addSecretIngredient(std::vector<std::string> &my_list, const std::vector<std::string> &friends_list) {
    my_list.back() = friends_list.back();
}

std::vector<double> scaleRecipe(const std::vector<double> quans_two_portions, unsigned num_portions) {
    std::vector<double> ret;
    std::transform(quans_two_portions.cbegin(), quans_two_portions.cend(), std::back_inserter(ret), [&num_portions](const double &quans) {
        return quans / 2.0 * num_portions;
    });
    return ret;
}

void addSecretIngredient(std::vector<std::string> &my_list, const std::string &auties_secret) {
    my_list.back() = auties_secret;
}

}  // namespace lasagna_master
