#ifndef CO_OP_BALL_GAME_UTILS_H
#define CO_OP_BALL_GAME_UTILS_H

#include "manager_methods.h"

std::string intToString(int value) {
    std::string str = std::to_string(value);
    return str;
}

GLfloat returnRandomFloatBetween0and1() {
    srand(time(nullptr));
    return (GLfloat)rand()/(GLfloat)RAND_MAX;
}

#endif //CO_OP_BALL_GAME_UTILS_H
