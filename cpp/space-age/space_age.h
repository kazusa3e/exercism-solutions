#pragma once

namespace space_age {

constexpr unsigned long long sec_in_earth_year = 31'557'600;

constexpr double mercury_orbital_period = 0.2408467;
constexpr double venus_orbital_period = 0.61519726;
constexpr double mars_orbital_period = 1.8808158;
constexpr double jupiter_orbital_period = 11.862615;
constexpr double saturn_orbital_period = 29.447498;
constexpr double uranus_orbital_period = 84.016846;
constexpr double neptune_orbital_period = 164.79132;

class space_age {
public:
    space_age(unsigned long long sec)
        : sec_(sec) {}

public:
    unsigned long long seconds() const {
        return sec_;
    }
    double on_earth() const;
    double on_mercury() const;
    double on_venus() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;

private:
    unsigned long long sec_ {0};
};

}  // namespace space_age
