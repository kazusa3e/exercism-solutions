#include "space_age.h"

namespace space_age {

double space_age::on_earth() const {
    return static_cast<double>(sec_) / sec_in_earth_year;
}

double space_age::on_mercury() const {
    return on_earth() / mercury_orbital_period;
}

double space_age::on_venus() const {
    return on_earth() / venus_orbital_period;
}

double space_age::on_mars() const {
    return on_earth() / mars_orbital_period;
}

double space_age::on_jupiter() const {
    return on_earth() / jupiter_orbital_period;
}

double space_age::on_saturn() const {
    return on_earth() / saturn_orbital_period;
}

double space_age::on_uranus() const {
    return on_earth() / uranus_orbital_period;
}

double space_age::on_neptune() const {
    return on_earth() / neptune_orbital_period;
}
}  // namespace space_age
