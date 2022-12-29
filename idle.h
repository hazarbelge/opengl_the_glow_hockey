#ifndef CO_OP_BALL_GAME_IDLE_H
#define CO_OP_BALL_GAME_IDLE_H

#include "manager_methods.h"

bool goal_control() {
    if (ballX + ballRadius > goal2X2 && ballY >= goal2Y1 && ballY <= goal2Y2) {
        player1_won();
        return true;
    }
    if (ballX - ballRadius < goal1X2 && ballY >= goal1Y1 && ballY <= goal1Y2) {
        player2_won();
        return true;
    }

    return false;
}

bool collide_with_player_rectangles() {
    if (ballX - ballRadius <= player1.getPlayerX2() && ballY >= player1.getPlayerY1() && ballY <= player1.getPlayerY2()) {
        ballX = player1.getPlayerX2() + ballRadius;
        ballSpeedX = -ballSpeedX;
        return true;
    }

    if (ballX + ballRadius >= player2.getPlayerX1() && ballY >= player2.getPlayerY1() && ballY <= player2.getPlayerY2()) {
        ballX = player2.getPlayerX1() - ballRadius;
        ballSpeedX = -ballSpeedX;
        return true;
    }

    return false;
}

bool collide_with_top_bottom() {
    if(ballSpeedY > 0) {
        if (ballY + ballRadius + ballSpeedY >= WINDOW_HEIGHT/2 - padding) {
            ballY = WINDOW_HEIGHT/2 - padding;
            ballSpeedY = -ballSpeedY;
            return true;
        }
    } else {
        if (ballY - ballRadius - ballSpeedY <= -WINDOW_HEIGHT/2 + padding) {
            ballY = -WINDOW_HEIGHT/2 + padding;
            ballSpeedY = -ballSpeedY;
            return true;
        }
    }

    return false;
}

bool collide_with_left_right() {
    if ((ballY >= goal2Y1 && ballY <= goal2Y2) || (ballY >= goal1Y1 && ballY <= goal1Y2)) {
        return false;
    }

    if(ballSpeedX > 0) {
        if (ballX + ballRadius + ballSpeedX >= WINDOW_WIDTH/2 - padding) {
            ballX = WINDOW_WIDTH/2 - padding;
            ballSpeedX = -ballSpeedX;
            return true;
        }
    } else {
        if (ballX - ballRadius - ballSpeedX <= -WINDOW_WIDTH/2 + padding) {
            ballX = -WINDOW_WIDTH/2 + padding;
            ballSpeedX = -ballSpeedX;
            return true;
        }
    }

    return false;
}

bool collide_with_goal_rear_lines() {
    if (ballY + ballRadius >= goal2Y2 && ballY + ballRadius <= goal2Y2 + 10 && ballX >= goal2X1 && ballX <= goal2X2) {
        ballSpeedY = -ballSpeedY;
        return true;
    }
    if (ballY - ballRadius <= goal2Y1 && ballY + ballRadius >= goal2Y1 - 10 && ballX >= goal2X1 && ballX <= goal2X2) {
        ballSpeedY = -ballSpeedY;
        return true;
    }
    if (ballY + ballRadius >= goal1Y2 && ballY + ballRadius <= goal2Y2 + 10 && ballX >= goal1X2 && ballX <= goal1X1) {
        ballSpeedY = -ballSpeedY;
        return true;
    }
    if (ballY - ballRadius <= goal1Y1 && ballY + ballRadius >= goal2Y1 - 10 && ballX >= goal1X2 && ballX <= goal1X1) {
        ballSpeedY = -ballSpeedY;
        return true;
    }

    return false;
}

void ball_movement() {
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    if (goal_control()) {
        return;
    }
    if (collide_with_player_rectangles()) {
        return;
    }
    if (collide_with_top_bottom()) {
        return;
    }
    if (collide_with_left_right()) {
        return;
    }
    if (collide_with_goal_rear_lines()) {
        return;
    }
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
