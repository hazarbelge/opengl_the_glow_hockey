#ifndef CO_OP_BALL_GAME_MOUSE_H
#define CO_OP_BALL_GAME_MOUSE_H

#include <cstdlib>
#include "manager_methods.h"
#include "configurations.h"

void detect_menu_button_clicks(int button, int state, int x, int y) {
    GLfloat realX = (GLfloat)x - WINDOW_WIDTH/2;
    GLfloat realY = WINDOW_HEIGHT/2 - (GLfloat)y;

    for (int i = 0; i < 2; i++) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (realX >= menuButtons[i].getButtonX1() && realX <= menuButtons[i].getButtonX2() &&
                    realY >= menuButtons[i].getButtonY1() && realY <= menuButtons[i].getButtonY2()) {
                menuButtons[i].onClick();
            }
        }
    }
}

void mouse(int button, int state, int x, int y) {
    if (!gameStarted) {
        detect_menu_button_clicks(button, state, x, y);
    }
    glutPostRedisplay();
}

#endif //CO_OP_BALL_GAME_MOUSE_H
