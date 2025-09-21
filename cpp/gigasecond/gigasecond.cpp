#include "gigasecond.h"

using namespace boost::posix_time;

namespace gigasecond {

ptime advance(const ptime &n) {
    const time_duration dur = seconds{ 1'000'000'000 };
    return n + dur;
}

}  // namespace gigasecond
