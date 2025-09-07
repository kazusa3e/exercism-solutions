#include "power_of_troy.h"

namespace troy {

void give_new_artifact(human &h, const std::string &p) {
    h.possession.reset(new artifact {p});
}

void exchange_artifacts(std::unique_ptr<artifact> &lhs, std::unique_ptr<artifact> &rhs) {
    std::swap(lhs, rhs);
}

void manifest_power(human &h, const std::string &p) {
    h.own_power.reset(new power {p});
}

void use_power(const human &from, human &to) {
    to.influenced_by = from.own_power;
}

int power_intensity(const human &h) {
    return h.own_power.use_count();
}

}  // namespace troy
