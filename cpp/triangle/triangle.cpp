#include "triangle.h"
#include <algorithm>
#include <array>
#include <stdexcept>

namespace triangle {

flavor kind(double a, double b, double c) {
    std::array<double, 3> arr{ a, b, c };
    std::sort(arr.begin(), arr.end());

    auto &[x, y, z] = arr;

    if (x + y < z) throw std::domain_error{ "" };
    if (x == 0 && z == 0) throw std::domain_error{ "" };

    if (x == z) return flavor::equilateral;
    if (x == y || y == z) return flavor::isosceles;
    return flavor::scalene;
}

}  // namespace triangle
