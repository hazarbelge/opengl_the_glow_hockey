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
    resetBall();
    glutIdleFunc(idle);
    game_over = false;
}

void endGame() {
    glutIdleFunc(nullptr);
    current_second = 0;
    glutTimerFunc(2000, startGame, 0);
}

void setWinnerText(std::string str) {
    winnerStr = std::move(str);
}

void player1_won() {
    glColor3f(0.0, 1.0, 0.0);
    glRasterPos2f(0, 0);
    game_over = true;
    setWinnerText("Player 1 won!");
    player1score++;
    endGame();
}

void player2_won() {
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(0, 0);
    game_over = true;
    setWinnerText("Player 2 won!");
    player2score++;
    endGame();
}

#endif //CO_OP_BALL_GAME_MANAGER_H
