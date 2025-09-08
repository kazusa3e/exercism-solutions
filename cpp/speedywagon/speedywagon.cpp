#include "speedywagon.h"
#include <numeric>

namespace speedywagon {

// Enter your code below:
bool connection_check(const pillar_men_sensor *sensor) {
    return sensor != nullptr;
}

unsigned activity_counter(pillar_men_sensor *sensors, unsigned sensors_len) {
    return std::accumulate(sensors, sensors + sensors_len, 0u,
                           [](const int acc, const pillar_men_sensor &curr) {
                               if (!connection_check(&curr)) return acc;
                               return acc + curr.activity;
                           });
}

bool alarm_control(const pillar_men_sensor *sensor) {
    if (!connection_check(sensor)) return false;
    return sensor->activity > 0;
}

bool uv_alarm(pillar_men_sensor *sensor) {
    if (!connection_check(sensor)) return false;
    return (uv_light_heuristic(&(sensor->data)) > sensor->activity);
}

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int> *data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
