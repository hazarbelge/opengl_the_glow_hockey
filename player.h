#ifndef CO_OP_BALL_GAME_PLAYER_H
#define CO_OP_BALL_GAME_PLAYER_H

#include "manager_methods.h"

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

    void stopPlayer();

    void setPlayerScore(int score);

    [[nodiscard]] int getPlayerScore() const;

    [[nodiscard]] GLfloat getPlayerX1() const;

    [[nodiscard]] GLfloat getPlayerY1() const;

    [[nodiscard]] GLfloat getPlayerX2() const;

    [[nodiscard]] GLfloat getPlayerY2() const;

    GLfloat getPlayerSpeed();

    GLint getPlayerNumber();
};

inline Player::Player(GLint playerNumber, GLfloat playerX1, GLfloat playerY1, GLfloat playerWidth, GLfloat playerHeight,
                      GLfloat playerSpeed) :
        playerNumber(playerNumber), playerX1(playerX1), playerY1(playerY1), playerWidth(playerWidth), playerHeight(playerHeight),
        playerSpeed(playerSpeed), playerScore(0) {}

inline void Player::drawPlayer() const {
    if (playerNumber == 1) {
        glColor3f(1, 0.0, 0.0);
    } else {
        glColor3f(0.0, 0.0, 1);
    }
    glBegin(GL_POLYGON);
    glVertex2f(getPlayerX1(), getPlayerY2());
    glVertex2f(getPlayerX2(), getPlayerY2());
    glVertex2f(getPlayerX2(), getPlayerY1());
    glVertex2f(getPlayerX1(), getPlayerY1());
    glEnd();
}

inline void Player::movePlayerUp() {
    playerY1 += playerSpeed;
}

inline void Player::movePlayerDown() {
    playerY1 -= playerSpeed;
}

inline void Player::stopPlayer() {
    playerSpeed = 0;
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
