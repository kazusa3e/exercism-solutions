#pragma once

#include <memory>
#include <utility>
namespace queen_attack {

using pos_t = std::pair<int, int>;

class chess_board {
public:
    chess_board() = delete;
    chess_board(const pos_t &white, const pos_t &black);
    ~chess_board();
    pos_t white() const;
    pos_t black() const;
    bool can_attack() const;

private:
    class chess_board_impl_;
    std::unique_ptr<chess_board_impl_> impl_;
};

}  // namespace queen_attack
