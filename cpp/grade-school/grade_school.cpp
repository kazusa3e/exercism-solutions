#include "grade_school.h"

namespace grade_school {

struct school::school_impl_ {
    school::roster_t roster;
};

school::school() : impl_(std::make_unique<school_impl_>()) {}
school::~school() = default;

const school::roster_t &school::roster() const {
    return impl_->roster;
}

void school::add(const std::string &name, unsigned grade) {
    auto &bucket = impl_->roster[grade];
    const auto pos = std::lower_bound(bucket.begin(), bucket.end(), name);
    bucket.insert(pos, name);
}

std::vector<std::string> school::grade(unsigned grade) const {
    if (const auto pos = impl_->roster.find(grade); pos != impl_->roster.cend()) {
        return pos->second;
    }
    return {};
}

}  // namespace grade_school
