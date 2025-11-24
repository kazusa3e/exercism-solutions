#include "clock.h"
#include <cstdio>

namespace date_independent {

auto positive_mod(int a, int b) -> unsigned {
    return ((a % b) + b) % b;
}

constexpr unsigned HOURS_IN_DAY = 24;
constexpr unsigned MINUTES_IN_HOUR = 60;

auto clock::at(int hour, int minute) -> clock {
    const auto t = positive_mod(hour * MINUTES_IN_HOUR + minute, HOURS_IN_DAY * MINUTES_IN_HOUR);
    const auto h = positive_mod(t / MINUTES_IN_HOUR, HOURS_IN_DAY);
    return clock{ h, t % MINUTES_IN_HOUR };
}

clock::operator std::string() const {
    char buf[6];
    std::sprintf(buf, "%02d:%02d", hour_, minute_);
    return buf;
}

auto clock::plus(int minutes) -> clock& {
    const auto t = positive_mod(this->hour_ * MINUTES_IN_HOUR + this->minute_ + minutes, HOURS_IN_DAY * MINUTES_IN_HOUR);
    const auto h = positive_mod(t / MINUTES_IN_HOUR, HOURS_IN_DAY);
    this->hour_ = h;
    this->minute_ = t % MINUTES_IN_HOUR;
    return *this;
}

auto clock::operator==(const clock &o) const -> bool {
    if (this == &o) return true;
    return this->hour_ == o.hour_ && this->minute_ == o.minute_;
}

}  // namespace date_independent
