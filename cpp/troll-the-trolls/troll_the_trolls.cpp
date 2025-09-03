namespace hellmath {

// Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus {
    mod,
    user,
    guest,
    troll,
};

// Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum class Action {
    read,
    write,
    remove,
};


// Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(const AccountStatus &poster, const AccountStatus &viewer) {
    if (poster != AccountStatus::troll) return true;
    return (viewer == AccountStatus::troll);
}

// Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(const Action &action, const AccountStatus &account_status) {
    if (account_status == AccountStatus::guest) {
        return (action == Action::read);
    }
    if (account_status == AccountStatus::troll) {
        return (action == Action::read) || (action == Action::write);
    }
    if (account_status == AccountStatus::user) {
        return (action == Action::read) || (action == Action::write);
    }
    if (account_status == AccountStatus::mod) {
        return (action == Action::read) || (action == Action::write) || (action == Action::remove);
    }
    return {};
}

// Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(const AccountStatus &lhs, const AccountStatus &rhs) {
    if (lhs == AccountStatus::guest || rhs == AccountStatus::guest) return false;
    if (lhs == AccountStatus::troll || rhs == AccountStatus::troll) {
        if (lhs == AccountStatus::troll && rhs == AccountStatus::troll) return true;
        return false;
    }
    return true;
}

// Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority(const AccountStatus &lhs, const AccountStatus &rhs) {
    return (static_cast<int>(lhs) < static_cast<int>(rhs));
}

}  // namespace hellmath
