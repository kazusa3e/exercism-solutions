#pragma once

#include <string>

namespace star_map {

enum class System {
    Sol,
    BetaHydri,
    EpsilonEridani,
    AlphaCentauri,
    DeltaEridani,
    Omicron2Eridani
};

}

namespace heaven {

class Vessel {
public:
    Vessel() = delete;
    Vessel(std::string &&_name, unsigned _generation)
        : name(std::move(_name)), generation(_generation) {}
    Vessel(std::string &&_name, unsigned _generation, star_map::System _system)
        : name(std::move(_name)), generation(_generation), current_system(_system) {}

    Vessel replicate(std::string &&name) const;
    void make_buster();
    bool shoot_buster();

public:
    std::string name;
    unsigned generation;
    star_map::System current_system {star_map::System::Sol};
    unsigned busters {0};
};

std::string get_older_bob(const Vessel &lhs, const Vessel &rhs);
bool in_the_same_system(const Vessel &lhs, const Vessel &rhs);

}
