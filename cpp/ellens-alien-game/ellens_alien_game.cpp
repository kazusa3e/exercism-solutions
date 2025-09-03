namespace targets {

class Alien {
public:
    int x_coordinate;
    int y_coordinate;

public:
    Alien(int x, int y): x_coordinate(x), y_coordinate(y) {}
    int get_health() const { return health_; }
    bool hit();
    bool is_alive() const { return health_ != 0; }
    bool teleport(int x, int y);
    bool collision_detection(const Alien &rhs);

private:
    int health_ {3};
};

bool Alien::hit() {
    if (is_alive()) {
        --this->health_;
        return true;
    }
    return false;
}

bool Alien::teleport(int x, int y) {
    if (is_alive()) {
        this->x_coordinate = x;
        this->y_coordinate = y;
        return true;
    }
    return false;
}

bool Alien::collision_detection(const Alien &rhs) {
    if (!this->is_alive() || !rhs.is_alive()) return false;
    return this->x_coordinate == rhs.x_coordinate && this->y_coordinate == rhs.y_coordinate;
}

}  // namespace targets
