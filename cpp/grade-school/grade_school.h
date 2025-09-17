#pragma once

#include <map>
#include <memory>
#include <vector>
#include <string>

namespace grade_school {

class school {
public:
    using roster_t = std::map<int, std::vector<std::string>>;

public:
    school();
    ~school();
    const roster_t &roster() const;
    void add(const std::string &name, unsigned grade);
    std::vector<std::string> grade(unsigned) const;

private:
    struct school_impl_;
    std::unique_ptr<school_impl_> impl_;
};

}  // namespace grade_school
