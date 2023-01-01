#ifndef CO_OP_BALL_GAME_MANAGER_H
#define CO_OP_BALL_GAME_MANAGER_H

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include "utils.h"
#include "configurations.h"
#include "display.h"
#include "idle.h"
#include "manager_methods.h"
#include "player.h"
#include "button.h"
#include "mouse.h"
#include "keyboard.h"

void startGame([[maybe_unused]] int value) {
    resetBall();
    glutIdleFunc(idle);
    is_player_scored = false;
    player_scored = 0;
}

void endGame() {
    glutIdleFunc(nullptr);
    current_second = 0;
    glutTimerFunc(2000, startGame, 0);
}

void setGoalText(std::string str) {
    goalTextString = std::move(str);
}

void player1_won() {
    glColor3f(0.0, 1.0, 0.0);
    glRasterPos2f(0, 0);
    is_player_scored = true;
    player_scored = 1;
    setGoalText("Goal by PLAYER 1!");
    player1.setPlayerScore(player1.getPlayerScore() + 1);
    endGame();
}

void player2_won() {
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(0, 0);
    is_player_scored = true;
    player_scored = 2;
    setGoalText("Goal by PLAYER 2!");
    player2.setPlayerScore(player2.getPlayerScore() + 1);
    endGame();
}

#endif //CO_OP_BALL_GAME_MANAGER_H
