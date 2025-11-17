#pragma once

#include <random>
#include <string>
#include <unordered_set>
namespace robot_name {

class robot {
public:
    robot();
    ~robot();
    auto name() const -> const std::string & { return this->name_; }
    auto reset() -> void;

private:
    std::string name_;

private:
    auto gen_name() -> std::string;

private:
    static inline std::random_device rd_ {};
    static inline std::mt19937 gen_ {rd_()};
    static inline std::unordered_set<std::string> name_set_ {};
};

}  // namespace robot_name
