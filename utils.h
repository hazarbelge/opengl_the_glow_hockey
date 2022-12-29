#ifndef CO_OP_BALL_GAME_UTILS_H
#define CO_OP_BALL_GAME_UTILS_H

#include "manager_methods.h"
#include <random>

std::string intToString(int value) {
    std::string str = std::to_string(value);
    return str;
}

void resetRandomSeedWith() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000000);
    srand(dis(gen));
}

GLfloat returnRandomFloatBetween(GLfloat min, GLfloat max) {
    resetRandomSeedWith();
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::uniform_real_distribution<GLfloat> uni(min, max);
    return uni(rng);
}

GLfloat returnRandomFloatBetween0and1() {
    returnRandomFloatBetween(0, 1);
}

void line_loop(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

#endif //CO_OP_BALL_GAME_UTILS_H
