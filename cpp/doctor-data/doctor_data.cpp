#include "doctor_data.h"

heaven::Vessel heaven::Vessel::replicate(std::string &&name) const {
    return Vessel {std::move(name), this->generation + 1, this->current_system};
}

void heaven::Vessel::make_buster() {
    ++this->busters;
}

bool heaven::Vessel::shoot_buster() {
    if (this->busters == 0) return false;
    --this->busters;
    return true;
}

std::string heaven::get_older_bob(const Vessel &lhs, const Vessel &rhs) {
    return (lhs.generation < rhs.generation) ? lhs.name : rhs.name;
}

bool heaven::in_the_same_system(const Vessel &lhs, const Vessel &rhs) {
    return (lhs.current_system == rhs.current_system);
}
