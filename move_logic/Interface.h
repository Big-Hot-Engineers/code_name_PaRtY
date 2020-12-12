#ifndef ROBOTIC_WAY_INTERFACE_H
#define ROBOTIC_WAY_INTERFACE_H

#define MAP_SIZE 1024
#define OBSTACLE 1
#define SCAN_FIELD 5
#define SHORT_DISTANCE 20

class Interface {
private:
    Robot robot;
    std::vector<std::vector<int>> map;
public:
    Interface();
    void map_initialization();
    void random_movement();
    void random_movement_in_first_quadrant(int short_distance);
    void random_movement_in_second_quadrant(int short_distance);
    void random_movement_in_third_quadrant(int short_distance);
    void random_movement_in_fourth_quadrant(int short_distance);
    void move_to_wall();
    void move_near_wall();
    bool is_obstacle(int short_distance);
    bool is_wall_on_left(int short_distance);
    bool is_obstacle_on_straight(int short_distance);
};

#endif //ROBOTIC_WAY_INTERFACE_H
