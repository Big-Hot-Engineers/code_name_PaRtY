#include "main.h"
#include <cmath>

Interface::Interface() {
    map.resize(MAP_SIZE);
    for (auto& map_it : map) {
        map_it.resize(MAP_SIZE);
    }
}

void Interface::map_initialization() {
    robot.turn_around();
    move_to_wall();
    robot.turn_right();
    int old_x = robot.get_position()[0];
    int old_y = robot.get_position()[1];
    bool is_orientation_not_changed = true;
    bool is_quadrant_not_changed = true;
    int old_orientation = robot.get_orientation();
    int old_quadrant = robot.get_quadrant();
    while (!(abs(robot.get_position()[0] - old_x) < 5 && abs(robot.get_position()[1] - old_y) < 5) || is_orientation_not_changed || is_quadrant_not_changed) {
        move_near_wall();
        if (old_orientation != robot.get_orientation()) {
            is_orientation_not_changed = false;
        }
        if (old_quadrant != robot.get_quadrant()) {
            is_quadrant_not_changed = false;
        }
    }
    robot.stop();
}

void Interface::random_movement() {
    robot.turn_right();
    robot.turn_random_angle_on_right();
    while(true) {
        if (robot.get_quadrant() == FIRST_QUADRANT) {
            random_movement_in_first_quadrant(20);
        }
        if (robot.get_quadrant() == SECOND_QUADRANT) {
            random_movement_in_second_quadrant(20);
        }
        if (robot.get_quadrant() == THIRD_QUADRANT) {
            random_movement_in_third_quadrant(20);
        }
        if (robot.get_quadrant() == FOURTH_QUADRANT) {
            random_movement_in_fourth_quadrant(20);
        }
        if (robot.get_quadrant() == NO_QUADRANT) {
            robot.stop();
        }
    }
}

void Interface::move_to_wall() {
    while (!is_obstacle(SHORT_DISTANCE)) {
        robot.move_straight();
    }
    robot.stop();
}

void Interface::move_near_wall() {
    while (is_wall_on_left(SHORT_DISTANCE) && !is_obstacle_on_straight(SHORT_DISTANCE)) {
        robot.move_straight(); //TODO: implement PD-regulator with distance to wall
    }
    robot.stop();
    if (is_wall_on_left(SHORT_DISTANCE) && is_obstacle_on_straight(SHORT_DISTANCE)) {
        robot.turn_right();
    } else if (!is_wall_on_left(SHORT_DISTANCE) && !is_obstacle_on_straight(SHORT_DISTANCE)) {
        robot.turn_left();
    }
}

bool Interface::is_wall_on_left(int short_distance) { //TODO: implement better wall discovering
    int x = 0;
    int y = 0;
    if (robot.get_orientation() == UP) {
        x = robot.get_position()[0] - short_distance;
        y = robot.get_position()[1] + 5;
    } else if (robot.get_orientation() == DOWN) {
        x = robot.get_position()[0] + short_distance;
        y = robot.get_position()[1] - 5;
    } else if (robot.get_orientation() == RIGHT) {
        x = robot.get_position()[0] + 5;
        y = robot.get_position()[1] + short_distance;
    } else if (robot.get_orientation() == LEFT) {
        x = robot.get_position()[0] - 5;
        y = robot.get_position()[1] - short_distance;
    }
    for (int i = -5; i < 5; ++i) {
        for (int j = -5; j < 5; ++j) {
            if (map[x + i][y + j] == OBSTACLE) {
                return true;
            }
        }
    }
    return false;
}

bool Interface::is_obstacle_on_straight(int short_distance) {
    int x = 0;
    int y = 0;
    if (robot.get_orientation() == UP) {
        x = robot.get_position()[0];
        y = robot.get_position()[1] + short_distance;
    } else if (robot.get_orientation() == DOWN) {
        x = robot.get_position()[0];
        y = robot.get_position()[1] - short_distance;
    } else if (robot.get_orientation() == RIGHT) {
        x = robot.get_position()[0] + short_distance;
        y = robot.get_position()[1];
    } else if (robot.get_orientation() == LEFT) {
        x = robot.get_position()[0] - short_distance;
        y = robot.get_position()[1];
    }
    for (int i = -5; i < 5; i++) {
        if (map[x + i][y] == OBSTACLE) {
            return true;
        }
    }
    return false;
}

bool Interface::is_obstacle(int short_distance) {
    int scan_field = SCAN_FIELD;
    for (int i = -scan_field; i < scan_field; ++i) {
         if (robot.get_position()[0] + i < 0 || robot.get_position()[0] + i > MAP_SIZE) {
             scan_field = 0;
         }
    }
    for (int i = -scan_field; i < scan_field; ++i) {
        int x = 0;
        int y = 0;
        if (robot.get_orientation() == UP) {
            x = robot.get_position()[0] + i;
            y = robot.get_position()[1] + short_distance;
        } else if (robot.get_orientation() == DOWN) {
            x = robot.get_position()[0] + i;
            y = robot.get_position()[1] - short_distance;
        } else if (robot.get_orientation() == RIGHT) {
            x = robot.get_position()[0] + short_distance;
            y = robot.get_position()[1] + i;
        } else if (robot.get_orientation() == LEFT) {
            x = robot.get_position()[0] - short_distance;
            y = robot.get_position()[1] + i;
        }
        if (x < 0 || x > MAP_SIZE || y < 0 || y > MAP_SIZE) {
            continue;
        }
        if (map[x][y] == OBSTACLE) {
            return true;
        }
    }
   return false;
}

void Interface::random_movement_in_first_quadrant(int short_distance) {
    bool is_obstacle_found = false;
    while (!is_obstacle_found) {
        robot.move_straight();
        int x = robot.get_position()[0] - sin(robot.get_angle()) * short_distance;
        int y = robot.get_position()[1] + cos(robot.get_angle()) * short_distance;
        for (int i = -5; i < 5; ++i) {
            for (int j = -5; j < 5; ++j) {
                if (map[x + i][y + i] == OBSTACLE) {
                    is_obstacle_found = true;
                }
            }
        }
    }
    robot.stop();
    robot.turn_random_angle_on_right();
}
void Interface::random_movement_in_second_quadrant(int short_distance) {
    bool is_obstacle_found = false;
    while (!is_obstacle_found) {
        robot.move_straight();
        int x = robot.get_position()[0] - sin(robot.get_angle()) * short_distance;
        int y = robot.get_position()[1] + cos(robot.get_angle()) * short_distance;
        if (map[x][y] == OBSTACLE) {
            is_obstacle_found = true;
        }
    }
    robot.stop();
    robot.turn_random_angle_on_right();
}

void Interface::random_movement_in_third_quadrant(int short_distance) {
    bool is_obstacle_found = false;
    while (!is_obstacle_found) {
        robot.move_straight();
        int x = robot.get_position()[0] - sin(robot.get_angle()) * short_distance;
        int y = robot.get_position()[1] + cos(robot.get_angle()) * short_distance;
        if (map[x][y] == OBSTACLE) {
            is_obstacle_found = true;
        }
    }
    robot.stop();
    robot.turn_random_angle_on_right();
}

void Interface::random_movement_in_fourth_quadrant(int short_distance) {
    bool is_obstacle_found = false;
    while (!is_obstacle_found) {
        robot.move_straight();
        int x = robot.get_position()[0] - sin(robot.get_angle()) * short_distance;
        int y = robot.get_position()[1] + cos(robot.get_angle()) * short_distance;
        if (map[x][y] == OBSTACLE) {
            is_obstacle_found = true;
        }
    }
    robot.stop();
    robot.turn_random_angle_on_right();
}





