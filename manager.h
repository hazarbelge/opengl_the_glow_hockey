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

void special(int key, [[maybe_unused]] int x, [[maybe_unused]] int y)
{
    keyStates[key] = true;
}

void specialUp(int key, [[maybe_unused]] int x, [[maybe_unused]] int y)
{
    keyStates[key] = false;
}

void keyboard(unsigned char key, [[maybe_unused]] int x, [[maybe_unused]] int y)
{
    keyStates[key] = true;
}

void keyboardUp(unsigned char key, [[maybe_unused]] int x, [[maybe_unused]] int y)
{
    keyStates[key] = false;
}

void startGame([[maybe_unused]] int value) {
    player1.resetPosition();
    player2.resetPosition();
    resetBall();
    glutIdleFunc(idle);
    is_player_scored = false;
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
    setGoalText("Goal by Player 1");
    player1.setPlayerScore(player1.getPlayerScore() + 1);
    endGame();
}

void player2_won() {
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(0, 0);
    is_player_scored = true;
    setGoalText("Goal by Player 2!");
    player2.setPlayerScore(player2.getPlayerScore() + 1);
    endGame();
}

#endif //CO_OP_BALL_GAME_MANAGER_H
