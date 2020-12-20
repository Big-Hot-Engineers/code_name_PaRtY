#include <cmath>
#include <cstdlib>
#include <vector>
#include "../../driver/lib/main.h"

Robot::Robot(): position({START_X_POSITION, START_Y_POSITION}){}

std::vector<int> Robot::get_position() {
    return this->position;
}
void Robot::set_position(std::vector<int> position) {
    this->position = position;
}
double Robot::get_angle() {
    return this->angle;
}
void Robot::set_angle(double angle) {
    this->angle = angle;
}


int Robot::get_orientation() {
    if (angle > 315 && angle <= 45) {
        return UP;
    }
    if (angle > 45 && angle <= 135) {
        return LEFT;
    }
    if (angle > 135 && angle <= 225) {
        return DOWN;
    }
    if (angle > 225 && angle <= 315) {
        return RIGHT;
    }
    return 0;
}

int Robot::get_quadrant() {
    if (angle >= 270 && angle < 359.99) {
        return FIRST_QUADRANT;
    }
    if (angle >= 0 && angle < 90) {
        return SECOND_QUADRANT;
    }
    if (angle >= 90 && angle < 180) {
        return THIRD_QUADRANT;
    }
    if (angle >= 180 && angle < 270) {
        return FOURTH_QUADRANT;
    }
    return 0;
}

void Robot::set_drivers_velocity(double left_driver_velocity, double right_driver_velocity) {
    this->left_driver_velocity = left_driver_velocity;
    this->right_driver_velocity = right_driver_velocity;
}

void Robot::stop() {
    set_drivers_velocity(0, 0);
}

void Robot::turn_around() {
    bool is_orientation_not_changed = true;
    bool is_quadrant_not_changed = true;
    double initial_angle = get_angle();
    double current_angle = initial_angle;
    int old_orientation = get_orientation();
    int old_quadrant = get_quadrant();
    while(fabs(current_angle - initial_angle) > 1 || is_orientation_not_changed || is_quadrant_not_changed) {
        if (old_orientation != get_orientation()) {
            is_orientation_not_changed = false;
        }
        if (old_quadrant != get_quadrant()) {
            is_quadrant_not_changed = false;
        }
        set_drivers_velocity(MAX_VELOCITY/2, -MAX_VELOCITY/2);
        current_angle = get_angle();
    }
    stop();
}

void Robot::turn_right() {
    bool is_orientation_not_changed = true;
    bool is_quadrant_not_changed = true;
    double initial_angle = get_angle();
    double current_angle = initial_angle;
    int old_orientation = get_orientation();
    int old_quadrant = get_quadrant();
    while(fabs(sin(initial_angle) - sin(current_angle + 90)) > 0.01 || is_orientation_not_changed || is_quadrant_not_changed) {
        if (old_orientation != get_orientation()) {
            is_orientation_not_changed = false;
        }
        if (old_quadrant != get_quadrant()) {
            is_quadrant_not_changed = false;
        }
        set_drivers_velocity(-MAX_VELOCITY/2, MAX_VELOCITY/2);
        current_angle = get_angle();
    }
    stop();
}

void Robot::turn_left() {
    bool is_orientation_not_changed = true;
    bool is_quadrant_not_changed = true;
    double initial_angle = get_angle();
    double current_angle = initial_angle;
    int old_orientation = get_orientation();
    int old_quadrant = get_quadrant();
    while(fabs(sin(initial_angle) - sin(current_angle - 90)) > 0.01 || is_orientation_not_changed || is_quadrant_not_changed) {
        if (old_orientation != get_orientation()) {
            is_orientation_not_changed = false;
        }
        if (old_quadrant != get_quadrant()) {
            is_quadrant_not_changed = false;
        }
        set_drivers_velocity(MAX_VELOCITY/2, -MAX_VELOCITY/2);
        current_angle = get_angle();
    }
    stop();
}

void Robot::turn_random_angle_on_right() {
    int random_angle = rand() % 50 + 10;
    double initial_angle = get_angle();
    double diff_angle= 0;
    double old_angle = initial_angle;
    bool zero_intersection = false;
    while(diff_angle != random_angle) {
        double current_angle = get_angle();
        if (fabs(old_angle - current_angle) > 355) {
            zero_intersection = true;
        }
        if (!zero_intersection) {
            diff_angle = initial_angle - current_angle;
        } else {
            diff_angle = initial_angle + (360 - current_angle);
        }
        set_drivers_velocity(MAX_VELOCITY/2, -MAX_VELOCITY/2);
        old_angle = current_angle;
    }
    stop();
}

void Robot::move_straight() {
    double pd_coeff = 0.1;
    double initial_angle = get_angle();
    double add_velocity = pd_coeff * (get_angle() - initial_angle);
    set_drivers_velocity(MAX_VELOCITY/2 + add_velocity, MAX_VELOCITY/2 - add_velocity);
}
