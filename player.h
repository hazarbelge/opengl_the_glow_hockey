#ifndef CO_OP_BALL_GAME_PLAYER_H
#define CO_OP_BALL_GAME_PLAYER_H

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

class Player {
    GLint playerNumber;
    GLfloat playerX1;
    GLfloat playerY1;
    GLfloat playerWidth;
    GLfloat playerHeight;
    GLfloat playerSpeed;
    GLint playerScore;
public:
    explicit Player(GLint playerNumber, GLfloat playerX1, GLfloat playerY1, GLfloat playerWidth, GLfloat playerHeight,
                    GLfloat playerSpeed);

    void drawPlayer() const;

    void movePlayerUp();

    void movePlayerDown();

    void setPlayerScore(int score);

    [[nodiscard]] int getPlayerScore() const;

    [[nodiscard]] GLfloat getPlayerX1() const;

    [[nodiscard]] GLfloat getPlayerY1() const;

    [[nodiscard]] GLfloat getPlayerX2() const;

    [[nodiscard]] GLfloat getPlayerY2() const;
};

inline Player::Player(GLint playerNumber, GLfloat playerX1, GLfloat playerY1, GLfloat playerWidth, GLfloat playerHeight,
                      GLfloat playerSpeed) :
        playerNumber(playerNumber), playerX1(playerX1), playerY1(playerY1), playerWidth(playerWidth), playerHeight(playerHeight),
        playerSpeed(playerSpeed), playerScore(0) {}

inline void Player::drawPlayer() const {
    int index;
    if (playerNumber == 1) {
        index = 6;
    } else {
        index = 7;
    }
    texture_drawer(getPlayerX1() - (GLfloat)1.5, getPlayerY1() - (GLfloat)0.5, getPlayerX2() + (GLfloat)1.5, getPlayerY2() + (GLfloat)0.5, index, 0.75);
}

inline void Player::movePlayerUp() {
    playerY1 += playerSpeed;
}

inline void Player::movePlayerDown() {
    playerY1 -= playerSpeed;
}

inline void Player::setPlayerScore(int score) {
    playerScore = score;
}

inline GLint Player::getPlayerScore() const {
    return playerScore;
}

inline GLfloat Player::getPlayerX1() const {
    return playerX1;
}

inline GLfloat Player::getPlayerY1() const {
    return playerY1;
}

inline GLfloat Player::getPlayerX2() const {
    return getPlayerX1() + playerWidth;
}

inline GLfloat Player::getPlayerY2() const {
    return getPlayerY1() + playerHeight;
}

#endif //CO_OP_BALL_GAME_PLAYER_H
