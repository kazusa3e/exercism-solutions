#include "robot_name.h"
#include <random>

namespace robot_name {

auto robot::gen_name() -> std::string {
    const auto gen_fn = []() -> std::string {
        std::uniform_int_distribution<> letter0(0, 25);
        std::uniform_int_distribution<> letter1(0, 25);
        std::uniform_int_distribution<> digit0(0, 9);
        std::uniform_int_distribution<> digit1(0, 9);
        std::uniform_int_distribution<> digit2(0, 9);

        return std::string{
            static_cast<char>(letter0(gen_) + 'A'),
            static_cast<char>(letter1(gen_) + 'A'),
            static_cast<char>(digit0(gen_) + '0'),
            static_cast<char>(digit1(gen_) + '0'),
            static_cast<char>(digit2(gen_) + '0'),
        };
    };

    auto ret = std::string{};
    auto pos = decltype(name_set_)::iterator{};
    do {
        ret = gen_fn();
        pos = name_set_.find(ret);
    } while (pos != name_set_.end());
    return ret;
}

robot::robot() {
    this->name_ = gen_name();
    name_set_.insert(this->name_);
}

robot::~robot() {
    // name_set_.erase(name_set_.find(this->name_));
}

auto robot::reset() -> void {
    robot tmp;
    std::swap(*this, tmp);
}

}  // namespace robot_name
