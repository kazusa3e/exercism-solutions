#include "queen_attack.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

namespace queen_attack {

class chess_board::chess_board_impl_ {
public:
    pos_t white;
    pos_t black;
};

chess_board::chess_board(const pos_t &white, const pos_t &black)
    : impl_(std::make_unique<chess_board_impl_>()) {
    const std::vector<int> idx = {
        white.first, white.second, black.first, black.second
    };

    if (std::any_of(idx.begin(), idx.end(), [](const auto &i) {
            return i < 0 || i >= 8;
        })) {
        throw std::domain_error{ "" };
    }
    if (white == black) throw std::domain_error{ "" };

    impl_->white = white;
    impl_->black = black;
}

chess_board::~chess_board() {}

pos_t chess_board::white() const {
    return impl_->white;
}

pos_t chess_board::black() const {
    return impl_->black;
}

bool chess_board::can_attack() const {
    if (impl_->white.first == impl_->black.first) return true;
    if (impl_->white.second == impl_->black.second) return true;
    if (impl_->white.first - impl_->white.second == impl_->black.first - impl_->black.second) return true;
    if (impl_->white.first - impl_->black.first + impl_->white.second - impl_->black.second == 0) return true;
    return false;
}

}  // namespace queen_attack
