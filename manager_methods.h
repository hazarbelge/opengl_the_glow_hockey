#ifndef CO_OP_BALL_GAME_MANAGER_METHODS_H
#define CO_OP_BALL_GAME_MANAGER_METHODS_H

int player1score = 0;
int player2score = 0;
void keyboard(unsigned char key, [[maybe_unused]] int x, [[maybe_unused]] int y);
void keyboardUp(unsigned char key, [[maybe_unused]] int x, [[maybe_unused]] int y);
void special(int key, [[maybe_unused]] int x, [[maybe_unused]] int y);
void specialUp(int key, [[maybe_unused]] int x, [[maybe_unused]] int y);
void setWinnerText(std::string str);
void startGame(int value);
void endGame();
void player1_won();
void player2_won();

#endif //CO_OP_BALL_GAME_MANAGER_METHODS_H
