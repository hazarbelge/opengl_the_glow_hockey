#ifndef CO_OP_BALL_GAME_DISPLAY_H
#define CO_OP_BALL_GAME_DISPLAY_H

#include "manager_methods.h"

void goal_lines(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glLineWidth(5);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
    glLineWidth(1);
}

void goal_border_lines() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0, 1.0, 1.0, 0.4);
    line_loop(goal1X1, goal1Y1, goal1X1, goal1Y2);
    line_loop(goal2X1, goal2Y1, goal2X1, goal2Y2);
    glDisable(GL_BLEND);
}

void penalty_area_lines() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0, 1.0, 1.0, 0.4);
    line_loop(goal1X1, goal1Y1, goal1X1 + 100, goal1Y2);
    line_loop(goal2X1, goal1Y1, goal2X1 - 100, goal1Y2);
    glDisable(GL_BLEND);
}

void penalty_spots() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0, 1.0, 1.0, 0.4);
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex2f(goal1X1 + 50, goal1Y1 + goalHeight / 2);
    glVertex2f(goal2X1 - 50, goal2Y1 + goalHeight / 2);
    glEnd();
    glPointSize(1.0);
    glDisable(GL_BLEND);
}

void pitch_border_lines(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glBegin(GL_LINE_STRIP);
    glVertex2f(x1, y1);
    glVertex2f(x1, y2);
    glVertex2f(x2, y2);
    glVertex2f(x2, y1);
    glEnd();
}

void pitch_borders() {
    glColor3f(1.0, 1.0, 1.0);
    pitch_border_lines(goal1X1, goal1Y1, goal2X1, (GLfloat) (-WINDOW_HEIGHT / 2) + padding);
    pitch_border_lines(goal1X1, goal1Y2, goal2X1, (GLfloat) (WINDOW_HEIGHT / 2) - padding);
}

void pitch_lines() {
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, (GLfloat) (-WINDOW_HEIGHT / 2) + padding);
    glVertex2f(0.0, (GLfloat) (WINDOW_HEIGHT / 2) - padding);
    glEnd();
    glLineWidth(1.0);
}

void pitch_corner_quarter_circles() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 90; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = (GLfloat) (-WINDOW_WIDTH / 2) + padding + (pitchCornerRadius * cos(angle));
        GLfloat y = (GLfloat) (-WINDOW_HEIGHT / 2) + padding + (pitchCornerRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 90; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = (GLfloat) (-WINDOW_WIDTH / 2) + padding + (pitchCornerRadius * cos(angle));
        GLfloat y = (GLfloat) (WINDOW_HEIGHT / 2) - padding - (pitchCornerRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 90; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = (GLfloat) (WINDOW_WIDTH / 2) - padding - (pitchCornerRadius * cos(angle));
        GLfloat y = (GLfloat) (-WINDOW_HEIGHT / 2) + padding + (pitchCornerRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 90; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = (GLfloat) (WINDOW_WIDTH / 2) - padding - (pitchCornerRadius * cos(angle));
        GLfloat y = (GLfloat) (WINDOW_HEIGHT / 2) - padding - (pitchCornerRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
}

void pitch_center_circle() {
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = (GLfloat) 0.0 + (pitchCenterCircleRadius * cos(angle));
        GLfloat y = (GLfloat) 0.0 + (pitchCenterCircleRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
    glLineWidth(1.0);
}

void pitch_center_spot() {
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);
    glEnd();
    glPointSize(1.0);
}

void ball() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = ballX + (ballRadius * cos(angle));
        GLfloat y = ballY + (ballRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
}

void goal1() {
    glColor3f(0.8, 0.0, 0.0);
    goal_lines(goal1X1, goal1Y1, goal1X2, goal1Y2);
}

void goal2() {
    glColor3f(0.0, 0.0, 0.8);
    goal_lines(goal2X1, goal2Y1, goal2X2, goal2Y2);
}

void drawPlayers() {
    player1.drawPlayer();
    player2.drawPlayer();
}

void goal_text() {
    if (is_player_scored) {
        glColor3f(0.0, 0.0, 0.0);
        glRasterPos2f(-70, 0);
        for (char i: goalTextString) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
        }
    }
}

void timeText() {
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-30, WINDOW_HEIGHT / 2 - padding / 2 - 8);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'T');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'i');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'm');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ':');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
    for (char i: intToString(current_second)) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, i);
    }
}

void scoreText() {
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(-WINDOW_WIDTH / 2 + padding / 2 + 8, WINDOW_HEIGHT / 2 - padding / 2 - 8);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'S');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'c');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'o');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'r');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'e');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ':');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
    for (char i: intToString(player1.getPlayerScore())) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, i);
    }
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '-');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ' ');
    for (char i: intToString(player2.getPlayerScore())) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, i);
    }
}

void reshape([[maybe_unused]] int w, [[maybe_unused]] int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WINDOW_WIDTH / 2, WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void displayInit() {
    player1 = Player(1, player1X1, player1Y1, playerWidth, playerHeight, playerSpeed);
    player2 = Player(2, player2X1, player2Y1, playerWidth, playerHeight, playerSpeed);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    pitch_borders();
    pitch_lines();
    pitch_corner_quarter_circles();
    pitch_center_circle();
    pitch_center_spot();
    goal1();
    goal2();
    goal_border_lines();
    penalty_area_lines();
    penalty_spots();
    drawPlayers();
    ball();
    timeText();
    scoreText();
    goal_text();
    glFlush();
}

#endif //CO_OP_BALL_GAME_DISPLAY_H
