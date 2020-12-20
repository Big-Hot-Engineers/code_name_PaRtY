#ifndef POSITION_ENC_POSITION_FROM_ENC_H
#define POSITION_ENC_POSITION_FROM_ENC_H

#include <vector>

#define N 400
#define wheel_l 20
#define pi 3.14
#define H 10

class Position_from_encoder {
 public:
    std::vector<double> pos;
    double angle;
    void change_pos_and_angle();
};

#endif //POSITION_ENC_POSITION_FROM_ENC_H
