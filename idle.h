#ifndef CO_OP_BALL_GAME_IDLE_H
#define CO_OP_BALL_GAME_IDLE_H

#include "manager_methods.h"

void goal_control() {
    if (ballX > goal2X1 + goalWidth/3 && ballY >= goal2Y1 && ballY <= goal2Y2) {
        player1_won();
    }
    if (ballX < goal1X1 - goalWidth/3 && ballY >= goal1Y1 && ballY <= goal1Y2) {
        player2_won();
    }
}

void collide_with_player_rectangles() {
    if (ballX - ballRadius <= player1.getPlayerX2() && ballY >= player1.getPlayerY1() && ballY <= player1.getPlayerY2()) {
        ballX = player1.getPlayerX2() + ballRadius;
        ballSpeedX = -ballSpeedX;
    }

    if (ballX + ballRadius >= player2.getPlayerX1() && ballY >= player2.getPlayerY1() && ballY <= player2.getPlayerY2()) {
        ballX = player2.getPlayerX1() - ballRadius;
        ballSpeedX = -ballSpeedX;
    }
}

void collide_with_top_bottom() {
    if (ballY + ballRadius >= WINDOW_HEIGHT/2 - padding) {
        ballSpeedY = -ballSpeedY;
    }
    if (ballY - ballRadius <= -WINDOW_HEIGHT/2 + padding) {
        ballSpeedY = -ballSpeedY;
    }
}

void collide_with_left_right() {
    if ((ballY >= goal2Y1 && ballY <= goal2Y2) || (ballY >= goal1Y1 && ballY <= goal1Y2)) {
        return;
    }

    if (ballX + ballRadius >= WINDOW_WIDTH/2 - padding) {
        ballSpeedX = -ballSpeedX;
    }
    if (ballX - ballRadius <= -WINDOW_WIDTH/2 + padding) {
        ballSpeedX = -ballSpeedX;
    }
}

void ball_movement() {
    goal_control();
    collide_with_player_rectangles();
    collide_with_top_bottom();
    collide_with_left_right();

    ballX += ballSpeedX;
    ballY += ballSpeedY;
}

void speedUpBall() {
    if (ballSpeedX > 0) {
        ballSpeedX += returnRandomFloatBetween(0.001, 0.005);
    } else {
        ballSpeedX -= returnRandomFloatBetween(0.001, 0.005);
    }
    if (ballSpeedY > 0) {
        ballSpeedY += returnRandomFloatBetween(0.001, 0.005);
    } else {
        ballSpeedY -= returnRandomFloatBetween(0.001, 0.005);
    }
}

void key_controls() {
    if (keyStates['w']) {
        if (player1.getPlayerY2() <= goal1Y2) {
            player1.movePlayerUp();
        }
    }
    if (keyStates['s']) {
        if (player1.getPlayerY1() >= goal1Y1) {
            player1.movePlayerDown();
        }
    }

    if (keyStates[GLUT_KEY_UP]) {
        if (player2.getPlayerY2() <= goal2Y2) {
            player2.movePlayerUp();
        }
    }
    if (keyStates[GLUT_KEY_DOWN]) {
        if (player2.getPlayerY1() >= goal2Y1) {
            player2.movePlayerDown();
        }
    }
}

void idle() {
    key_controls();
    ball_movement();
    speedUpBall();
    glutPostRedisplay();
}

#endif //CO_OP_BALL_GAME_IDLE_H
