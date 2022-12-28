#ifndef CO_OP_BALL_GAME_CONFIGURATIONS_H
#define CO_OP_BALL_GAME_CONFIGURATIONS_H

#include "manager_methods.h"

#define pi 3.14159265358979323846

GLfloat WINDOW_WIDTH = 1000;
GLfloat WINDOW_HEIGHT = 500;
GLfloat padding = 50.0;

GLfloat goalWidth = 25.0;
GLfloat goalHeight = WINDOW_HEIGHT/(GLfloat)2;

GLfloat playerWidth = 10.0;
GLfloat playerHeight = goalHeight/(GLfloat)3;
GLfloat playerSpeed = 6.0;

GLfloat goal1X1 = (GLfloat)(-WINDOW_WIDTH/2 + padding);
GLfloat goal1X2 = (GLfloat)(-WINDOW_WIDTH/2 + padding - goalWidth);
GLfloat goal1Y1 = (GLfloat)(-WINDOW_HEIGHT/2 + goalHeight/2);
GLfloat goal1Y2 = (GLfloat)(WINDOW_HEIGHT/2 - goalHeight/2);
GLfloat goal2X1 = (GLfloat)(WINDOW_WIDTH/2 - padding);
GLfloat goal2X2 = (GLfloat)(WINDOW_WIDTH/2 - padding + goalWidth);
GLfloat goal2Y1 = (GLfloat)(-WINDOW_HEIGHT/2 + goalHeight/2);
GLfloat goal2Y2 = (GLfloat)(WINDOW_HEIGHT/2 - goalHeight/2);
GLfloat player1X1 = (GLfloat)(goal1X1 - playerWidth/2);
GLfloat player1X2 = (GLfloat)(goal1X1 + playerWidth/2);
GLfloat player1Y1 = -playerHeight/(GLfloat)2.0;
GLfloat player1Y2 = playerHeight/(GLfloat)2.0;
GLfloat player2X1 = (GLfloat)(goal2X1 + playerWidth/2);
GLfloat player2X2 = (GLfloat)(goal2X1 - playerWidth/2);
GLfloat player2Y1 = -playerHeight/(GLfloat)2.0;
GLfloat player2Y2 = playerHeight/(GLfloat)2.0;

GLfloat ballRadius = 6.0;
GLfloat ballX = 0.0;
GLfloat ballY = 0.0;

GLfloat ballSpeedX = returnRandomFloatBetween0and1() * 2 + 4;
GLfloat ballSpeedY = returnRandomFloatBetween0and1() * 2 + 4;

GLfloat pitchCenterCircleRadius = 75.0;
GLfloat pitchCornerRadius = 20.0;

void resetBall() {
    ballX = 0.0;
    ballY = 0.0;
    ballSpeedX = returnRandomFloatBetween0and1() * 2 + 4;
    ballSpeedY = returnRandomFloatBetween0and1() * 2 + 4;
}

bool keyStates[256];

int current_second = 0;
bool game_over = false;
std::string winnerStr;

void timer([[maybe_unused]] int value) {
    current_second++;
    glutTimerFunc(1000, timer, current_second);
}

#endif //CO_OP_BALL_GAME_CONFIGURATIONS_H
