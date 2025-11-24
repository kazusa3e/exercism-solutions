#pragma once

#include <string>

namespace date_independent {

class clock {
public:
    static auto at(int hour, int minute) -> clock;
    explicit operator std::string() const;
    auto plus(int minutes) -> clock &;
    auto operator==(const clock &o) const -> bool;
    auto operator!=(const clock &o) const -> bool {
        return !(this == &o);
    }

private:
    clock(unsigned hour, unsigned minute)
        : hour_(hour), minute_(minute) {}

private:
    unsigned hour_{ 0 };
    unsigned minute_{ 0 };
};

}  // namespace date_independent
