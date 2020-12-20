#include "Position_from_enc.h"
#include <cmath>


void Position_from_encoder::change_pos_and_angle() {
    pos = get_pos();
    double angle_old = get_angle();
    int encoder = get_encoder();
    int right_driver_velocity = get_right_driver_velocity();
    int left_driver_velocity = get_left_driver_velocity();
    int move_state = get_move_state();
    if (move_state == MOVE_STRAIGHT) {
        pos[0] -= ((double)encoder * wheel_l / N) * sin(angle);
        pos[1] -= ((double)encoder * wheel_l / N) * cos(angle);
    } else if (move_state == TURN) {
        double angle_turn = encoder * wheel_l * 180 / (N * pi * H);
        if (right_driver_velocity > 0 && left_driver_velocity < 0) {
            if (angle_old + angle_turn > 360) {
                angle = angle_turn - (360 - angle_old);
            } else {
                angle = angle_old + angle_turn;
            }
        } else if (right_driver_velocity < 0 && left_driver_velocity > 0) {
            if (angle_old < angle_turn) {
                angle = 360 - (angle_turn - angle_old);
            } else {
                angle = angle_old - angle_turn;
            }
        }
    }
}
