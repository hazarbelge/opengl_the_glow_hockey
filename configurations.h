#ifndef CO_OP_BALL_GAME_CONFIGURATIONS_H
#define CO_OP_BALL_GAME_CONFIGURATIONS_H

#include "manager_methods.h"
#include "button.h"

#define pi 3.14

GLfloat WINDOW_WIDTH = 1200;
GLfloat WINDOW_HEIGHT = 900;
GLfloat padding = 50.0;
GLfloat paddingTop = 300.0;

GLfloat goalWidth = 30.0;
GLfloat goalHeight = (WINDOW_HEIGHT-paddingTop)/(GLfloat)2.0;

GLfloat playerWidth = 10.0;
GLfloat playerHeight = goalHeight/(GLfloat)3;

#ifdef __APPLE_CC__
GLfloat playerSpeed = 6.0;
#else
GLfloat playerSpeed = 0.75;
#endif

GLfloat goal1X1 = (GLfloat)(-WINDOW_WIDTH/2 + padding);
GLfloat goal1X2 = (GLfloat)(-WINDOW_WIDTH/2 + padding - goalWidth);
GLfloat goal1Y1 = (GLfloat)(-WINDOW_HEIGHT/2 + goalHeight/2);
GLfloat goal1Y2 = (GLfloat)(WINDOW_HEIGHT/2 - goalHeight/2 - paddingTop);
GLfloat goal2X1 = (GLfloat)(WINDOW_WIDTH/2 - padding);
GLfloat goal2X2 = (GLfloat)(WINDOW_WIDTH/2 - padding + goalWidth);
GLfloat goal2Y1 = (GLfloat)(-WINDOW_HEIGHT/2 + goalHeight/2);
GLfloat goal2Y2 = (GLfloat)(WINDOW_HEIGHT/2 - goalHeight/2 - paddingTop);
GLfloat player1X1 = (GLfloat)(goal1X1 - playerWidth/2);
GLfloat player1Y1 = -playerHeight/(GLfloat)2.0 - paddingTop/2;
GLfloat player2X1 = (GLfloat)(goal2X1 - playerWidth/2);
GLfloat player2Y1 = -playerHeight/(GLfloat)2.0 - paddingTop/2;

GLfloat ballRadius = 6.0;
GLfloat ballX = 0.0;
GLfloat ballY =  - paddingTop/2;

#ifdef __APPLE_CC__
GLfloat ballSpeedX = 7;
GLfloat ballSpeedY = 7;
#else
GLfloat ballSpeedX = 0.5;
GLfloat ballSpeedY = 0.5;
#endif

GLfloat pitchCenterCircleRadius = 80.0;
GLfloat pitchCornerRadius = 30.0;

void resetBall() {
    ballX = 0.0;
    ballY = 0.0;
#ifdef __APPLE_CC__
    ballSpeedX = returnRandomFloatBetween(6, 7);
    ballSpeedY = returnRandomFloatBetween(6, 7);
#else
    ballSpeedX = returnRandomFloatBetween(0.25, 0.75);
    ballSpeedY = returnRandomFloatBetween(0.25, 0.75);
#endif
}

bool gameStarted = false;
bool isSnowyDay = false;
bool isRainyDay = false;
bool showHowToPlay = true;

bool keyStates[256];

Button playButton = Button("Play", -60,0,120,50, []() {
    gameStarted = true;
});
Button exitButton = Button("Exit", -60,-120,120,50, []() {
    exit(0);
});

std::vector<Button> menuButtons = {playButton, exitButton};

int current_second = 0;
bool is_player_scored = false;
int player_scored = 0;
std::string goalTextString;

void timer([[maybe_unused]] int value) {
    if (gameStarted) {
        current_second++;
        glutTimerFunc(1000, timer, current_second);
    }
}

#endif //CO_OP_BALL_GAME_CONFIGURATIONS_H
