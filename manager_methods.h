#ifndef CO_OP_BALL_GAME_MANAGER_METHODS_H
#define CO_OP_BALL_GAME_MANAGER_METHODS_H

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "player.h"

Player player1 = Player(0, 0, 0, 0, 0, 0);
Player player2 = Player(0, 0, 0, 0, 0, 0);

void keyboard(unsigned char key, [[maybe_unused]] int x, [[maybe_unused]] int y);
void keyboardUp(unsigned char key, [[maybe_unused]] int x, [[maybe_unused]] int y);
void special(int key, [[maybe_unused]] int x, [[maybe_unused]] int y);
void specialUp(int key, [[maybe_unused]] int x, [[maybe_unused]] int y);
void setGoalText(std::string str);
void startGame(int value);
void endGame();
void player1_won();
void player2_won();

#endif //CO_OP_BALL_GAME_MANAGER_METHODS_H
