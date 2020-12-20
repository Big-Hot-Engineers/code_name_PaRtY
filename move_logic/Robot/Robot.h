#ifndef ROBOTIC_WAY_ROBOT_H
#define ROBOTIC_WAY_ROBOT_H

#include <vector>

#define START_X_POSITION 0
#define START_Y_POSITION 0
#define MAX_VELOCITY 10

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

#define NO_QUADRANT 0
#define FIRST_QUADRANT 1
#define SECOND_QUADRANT 2
#define THIRD_QUADRANT 3
#define FOURTH_QUADRANT 4

class Robot {
private:
    std::vector<int> position;
    double angle;
    double right_driver_velocity;
    double left_driver_velocity;
public:
    Robot();
    std::vector<int> get_position();
    void set_position(std::vector<int> position);
    double get_angle();
    void set_angle(double angle);
    int get_orientation();
    int get_quadrant();
    void set_drivers_velocity(double right_driver_velocity, double left_driver_velocity);
    void stop();
    void turn_around();
    void turn_right();
    void turn_left();
    void turn_random_angle_on_right();
    void move_straight();
};

#endif //ROBOTIC_WAY_ROBOT_H
