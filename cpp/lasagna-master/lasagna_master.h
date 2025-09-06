#pragma once

#include <algorithm>
#include <string>
#include <vector>
namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(const std::vector<std::string> &layers, int time_per_layer = 2);

constexpr int noddle_quantity = 50;
constexpr double sauce_quantity = 0.2;

amount quantities(const std::vector<std::string> &layers);

void addSecretIngredient(std::vector<std::string> &my_list, const std::vector<std::string> &friends_list);

std::vector<double> scaleRecipe(const std::vector<double> quans_two_portions, unsigned num_portions);

void addSecretIngredient(std::vector<std::string> &my_list, const std::string &auties_secret);

}  // namespace lasagna_master
