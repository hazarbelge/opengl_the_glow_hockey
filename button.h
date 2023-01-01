#ifndef CO_OP_BALL_GAME_BUTTON_H
#define CO_OP_BALL_GAME_BUTTON_H

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#include <cstring>

#else
#include <GL/freeglut.h>
#endif

class Button {
    char* text;
    GLfloat buttonX1;
    GLfloat buttonY1;
    GLfloat buttonWidth;
    GLfloat buttonHeight;
public:
    explicit Button(char* text, GLfloat buttonX1, GLfloat buttonY1, GLfloat buttonWidth, GLfloat buttonHeight, void (*onClick)());

    [[nodiscard]] char* getText() const;

    void drawButton() const;

    void drawButtonText() const;

    [[nodiscard]] GLfloat getButtonX1() const;

    [[nodiscard]] GLfloat getButtonY1() const;

    [[nodiscard]] GLfloat getButtonX2() const;

    [[nodiscard]] GLfloat getButtonY2() const;

    void (*onClick)();
};

inline Button::Button(char* text, GLfloat buttonX1, GLfloat buttonY1, GLfloat buttonWidth, GLfloat buttonHeight, void (*onClick)()) :
        text(text), buttonX1(buttonX1), buttonY1(buttonY1), buttonWidth(buttonWidth), buttonHeight(buttonHeight), onClick(onClick){}

inline void Button::drawButton() const {
    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_POLYGON);
    glVertex2f(getButtonX1(), getButtonY2());
    glVertex2f(getButtonX2(), getButtonY2());
    glVertex2f(getButtonX2(), getButtonY1());
    glVertex2f(getButtonX1(), getButtonY1());
    glEnd();
}

inline void Button::drawButtonText() const {
    glColor3f(0, 0, 0);
    glRasterPos2f((getButtonX1() + getButtonX2()) / 2 - 20, (getButtonY1() + getButtonY2()) / 2 - 8);
    for (int i = 0; i < strlen(text); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

inline GLfloat Button::getButtonX1() const {
    return buttonX1;
}

inline GLfloat Button::getButtonY1() const {
    return buttonY1;
}

inline GLfloat Button::getButtonX2() const {
    return getButtonX1() + buttonWidth;
}

inline GLfloat Button::getButtonY2() const {
    return getButtonY1() + buttonHeight;
}

inline char* Button::getText() const {
    return text;
}

#endif //CO_OP_BALL_GAME_BUTTON_H
