#include "difference_of_squares.h"

namespace difference_of_squares {

unsigned long long square_of_sum(unsigned n) {
    unsigned long long sum = n * (n + 1) / 2;
    return sum * sum;
}

unsigned long long sum_of_squares(unsigned n) {
    unsigned long long sum = 0;
    ++n;
    while (n--) sum += n * n;
    return sum;
}

long long difference(unsigned n) {
    return square_of_sum(n) - sum_of_squares(n);
}

}  // namespace difference_of_squares
