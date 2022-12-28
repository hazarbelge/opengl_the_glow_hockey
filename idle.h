#ifndef CO_OP_BALL_GAME_IDLE_H
#define CO_OP_BALL_GAME_IDLE_H

#include "manager_methods.h"

void goal_control() {
    if (ballX + ballRadius >= goal2X2 && ballY >= goal2Y1 && ballY <= goal2Y2) {
        player1_won();
    }
    if (ballX - ballRadius <= goal1X2 && ballY >= goal1Y1 && ballY <= goal1Y2) {
        player2_won();
    }
}

void collide_with_player_rectangles() {
    if (ballX + ballRadius >= player2X2 && ballY >= player2Y1 && ballY <= player2Y2) {
        ballX = player2X2 - ballRadius;
        ballSpeedX = -ballSpeedX;
    }
    if (ballX - ballRadius <= player1X2 && ballY >= player1Y1 && ballY <= player1Y2) {
        ballX = player1X2 + ballRadius;
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
        ballSpeedX += 0.001;
    } else {
        ballSpeedX -= 0.001;
    }
    if (ballSpeedY > 0) {
        ballSpeedY += 0.001;
    } else {
        ballSpeedY -= 0.001;
    }
}

void key_controls() {
    if (keyStates['w']) {
        if (player1Y2 <= goal1Y2) {
            player1Y1 += playerSpeed;
            player1Y2 += playerSpeed;
        }
    }
    if (keyStates['s']) {
        if (player1Y1 >= goal1Y1) {
            player1Y1 -= playerSpeed;
            player1Y2 -= playerSpeed;
        }
    }

    if (keyStates[GLUT_KEY_UP]) {
        if (player2Y2 <= goal2Y2) {
            player2Y1 += playerSpeed;
            player2Y2 += playerSpeed;
        }
    }
    if (keyStates[GLUT_KEY_DOWN]) {
        if (player2Y1 >= goal2Y1) {
            player2Y1 -= playerSpeed;
            player2Y2 -= playerSpeed;
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
