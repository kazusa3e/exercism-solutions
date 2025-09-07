#pragma once

#include <string>
#include <memory>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

class human {
public:

public:
    std::unique_ptr<artifact> possession;
    std::shared_ptr<power> own_power;
    std::shared_ptr<power> influenced_by;
};

void give_new_artifact(human &h, const std::string &p);
void exchange_artifacts(std::unique_ptr<artifact> &lhs, std::unique_ptr<artifact> &rhs);
void manifest_power(human &h, const std::string &p);
void use_power(const human &from, human &to);
int power_intensity(const human &h);

}  // namespace troy
