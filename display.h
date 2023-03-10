#ifndef CO_OP_BALL_GAME_DISPLAY_H
#define CO_OP_BALL_GAME_DISPLAY_H

#include "manager_methods.h"
#include "Texture.h"
#include "button.h"

char* filenameArray[9] = {
        (char*)"textures/pitch.bmp",
        (char*)"textures/stadium.bmp",
        (char*)"textures/menu_bg.bmp",
        (char*)"textures/ball.bmp",
        (char*)"textures/red_line.bmp",
        (char*)"textures/blue_line.bmp",
        (char*)"textures/red_line_ver.bmp",
        (char*)"textures/blue_line_ver.bmp",
        (char*)"textures/center_circle.bmp",
};

void stadium() {
    texture_drawer(-WINDOW_WIDTH/2, WINDOW_HEIGHT/2 - paddingTop, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 1, 0.8);
}

void pitch_background(){
    texture_drawer(-WINDOW_WIDTH/2, -WINDOW_HEIGHT/2, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0, 0.4);
}

void pitch_borders() {
    //red lines
    texture_drawer(goal1X1 - 4, goal1Y1, goal1X1 + 4, (GLfloat) (-WINDOW_HEIGHT / 2) + padding, 6);
    texture_drawer(goal1X1 - 2, (GLfloat) (-WINDOW_HEIGHT / 2) + padding - 4, 0,(GLfloat) (-WINDOW_HEIGHT / 2) + padding + 4, 4);
    texture_drawer(goal1X1 - 4, goal1Y2, goal1X1 + 4, (GLfloat) (WINDOW_HEIGHT / 2) - padding - paddingTop - 4, 6);
    texture_drawer(goal1X1 - 2, (GLfloat) (WINDOW_HEIGHT / 2) - padding - paddingTop - 4, 0,(GLfloat) (WINDOW_HEIGHT / 2) - padding - paddingTop + 4, 4);

    //blue lines
    texture_drawer(goal2X1 - 4, goal2Y1, goal2X1 + 4, (GLfloat) (-WINDOW_HEIGHT / 2) + padding, 7);
    texture_drawer(goal2X1 + 2, (GLfloat) (-WINDOW_HEIGHT / 2) + padding - 4, 0,(GLfloat) (-WINDOW_HEIGHT / 2) + padding + 4, 5);
    texture_drawer(goal2X1 - 4, goal2Y2, goal2X1 + 4, (GLfloat) (WINDOW_HEIGHT / 2) - padding - paddingTop - 4, 7);
    texture_drawer(goal2X1 + 2, (GLfloat) (WINDOW_HEIGHT / 2) - padding - paddingTop - 4, 0,(GLfloat) (WINDOW_HEIGHT / 2) - padding - paddingTop + 4, 5);
}

void pitch_center_lines() {
    texture_drawer(-5, (GLfloat) (-WINDOW_HEIGHT / 2) + padding, -1.5,
                   (GLfloat) (WINDOW_HEIGHT / 2) - padding - paddingTop, 6);
    texture_drawer(1.5, (GLfloat) (-WINDOW_HEIGHT / 2) + padding, 5,
                   (GLfloat) (WINDOW_HEIGHT / 2) - padding - paddingTop, 7);
}

void pitch_corner_quarter_circles() {
    glLineWidth(4.0);
    glColor3f(1, 0.3, 0.3);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 90; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = (GLfloat) (-WINDOW_WIDTH / 2) + padding + (pitchCornerRadius * cos(angle));
        GLfloat y = (GLfloat) (-WINDOW_HEIGHT / 2) + padding + (pitchCornerRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(1, 0.3, 0.3);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 90; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = (GLfloat) (-WINDOW_WIDTH / 2) + padding + (pitchCornerRadius * cos(angle));
        GLfloat y = (GLfloat) (WINDOW_HEIGHT / 2) - padding - paddingTop - (pitchCornerRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0.3, 0.3, 1.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 90; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = (GLfloat) (WINDOW_WIDTH / 2) - padding - (pitchCornerRadius * cos(angle));
        GLfloat y = (GLfloat) (-WINDOW_HEIGHT / 2) + padding + (pitchCornerRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0.3, 0.3, 1.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 90; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = (GLfloat) (WINDOW_WIDTH / 2) - padding - (pitchCornerRadius * cos(angle));
        GLfloat y = (GLfloat) (WINDOW_HEIGHT / 2) - padding - paddingTop- (pitchCornerRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
    glLineWidth(1.0);
}

void pitch_center_circle() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0, 1.0, 1.0, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureName[8]);
    glBegin(GL_POLYGON);
    for (int j = 0; j < 360; j++) {
        auto angle = (GLfloat) (j * pi / 180);
        auto xcos = (GLfloat)cos(angle);
        auto ysin = (GLfloat)sin(angle);
        auto x = xcos * (-pitchCenterCircleRadius + 1.5) + 0;
        auto y = ysin * (-pitchCenterCircleRadius + 1.5) - paddingTop/2;
        auto tx = xcos * 0.5 + 0.5;
        auto ty = ysin * 0.5 + 0.5;

        glTexCoord2f((GLfloat)tx, (GLfloat)ty);
        glVertex2f((GLfloat)x, (GLfloat)y);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
}

void pitch_center_spot() {
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(8.0);
    glBegin(GL_POLYGON);
    for (int j = 0; j < 360; j++) {
        auto angle = (GLfloat) (j * pi / 180);
        GLfloat x2 = (GLfloat) 0 + (5 * cos(angle));
        GLfloat y2 = (GLfloat) - paddingTop/2 + (5 * sin(angle));
        glVertex2f(x2, y2);
    }
    glEnd();
    glPointSize(1.0);
}

void drawPitch() {
    stadium();
    pitch_borders();
    pitch_center_circle();
    pitch_center_lines();
    pitch_background();
    pitch_corner_quarter_circles();
    pitch_center_spot();
}

void goal_border_lines() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0, 1.0, 1.0, 0.6);
    line_loop(goal1X1, goal1Y1, goal1X1, goal1Y2);
    line_loop(goal2X1, goal2Y1, goal2X1, goal2Y2);
    glDisable(GL_BLEND);
}

void penalty_area_lines() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0, 1.0, 1.0, 0.4);
    line_loop(goal1X1, goal1Y1, goal1X1 + WINDOW_WIDTH/12, goal1Y2);
    line_loop(goal2X1, goal1Y1, goal2X1 - WINDOW_WIDTH/12, goal1Y2);
    glDisable(GL_BLEND);
}

void penalty_area_half_circles(){
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0, 1.0, 1.0, 0.4);
    glBegin(GL_LINE_STRIP);
    for (int i = -90; i < 90; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = (GLfloat) goal1X1 + WINDOW_WIDTH/12 + (pitchCornerRadius * cos(angle));
        GLfloat y = (GLfloat) (goal1Y1 + goal1Y2)/2 + (pitchCornerRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (int i = 90; i < 270; i++) {
        auto angle = (GLfloat) (i * pi / 180);
        GLfloat x = (GLfloat) goal2X1 - WINDOW_WIDTH/12 + (pitchCornerRadius * cos(angle));
        GLfloat y = (GLfloat) (goal2Y1 + goal2Y2)/2 + (pitchCornerRadius * sin(angle));
        glVertex2f(x, y);
    }
    glEnd();
    glDisable(GL_BLEND);
}

void penalty_spots() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0, 1.0, 1.0, 0.4);
    glBegin(GL_POLYGON);
    for (int j = 0; j < 360; j++) {
        auto angle = (GLfloat) (j * pi / 180);
        GLfloat x2 = (GLfloat) goal1X1 + WINDOW_WIDTH/24 + (4 * cos(angle));
        GLfloat y2 = (GLfloat) goal1Y1 + goalHeight / 2 + (4 * sin(angle));
        glVertex2f(x2, y2);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int j = 0; j < 360; j++) {
        auto angle = (GLfloat) (j * pi / 180);
        GLfloat x2 = (GLfloat) goal2X1 - WINDOW_WIDTH/24 + (4 * cos(angle));
        GLfloat y2 = (GLfloat) goal2Y1 + goalHeight / 2 + (4 * sin(angle));
        glVertex2f(x2, y2);
    }
    glEnd();
    glDisable(GL_BLEND);
}

void goal1() {
    texture_drawer(goal1X2 - 4, goal1Y1, goal1X2 + 4, goal1Y2, 6);
    texture_drawer(goal1X1, goal1Y1 - 4, goal1X2, goal1Y1 + 4, 4);
    texture_drawer(goal1X1, goal1Y2 - 4, goal1X2, goal1Y2 + 4, 4);
}

void goal2() {
    texture_drawer(goal2X2 - 4, goal2Y1, goal2X2 + 4, goal2Y2, 7);
    texture_drawer(goal2X1, goal2Y1 - 4, goal2X2, goal2Y1 + 4, 5);
    texture_drawer(goal2X1, goal2Y2 - 4, goal2X2, goal2Y2 + 4, 5);
}

void drawGoals() {
    goal1();
    goal2();
    goal_border_lines();
    penalty_area_lines();
    penalty_area_half_circles();
    penalty_spots();
}

void ball() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureName[3]);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (int j = 0; j < 360; j++) {
        auto angle = (GLfloat) (j * pi / 180);
        auto xcos = (GLfloat)cos(angle);
        auto ysin = (GLfloat)sin(angle);
        auto x = xcos * (ballRadius + 1.5) + ballX;
        auto y = ysin * (ballRadius + 1.5) + ballY;
        auto tx = xcos * 0.5 + 0.5;
        auto ty = ysin * 0.5 + 0.5;

        glTexCoord2f((GLfloat)tx, (GLfloat)ty);
        glVertex2f((GLfloat)x, (GLfloat)y);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void drawPlayers() {
    player1.drawPlayer();
    player2.drawPlayer();
}

void snow_animation_foreground() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0, 1.0, 1.0, 0.8);
    for (int i = 0; i < 50; i++) {
        GLfloat x1 = returnRandomFloatBetween(-WINDOW_WIDTH/2, WINDOW_WIDTH/2);
        GLfloat y1 = returnRandomFloatBetween(-WINDOW_HEIGHT/2, WINDOW_HEIGHT/2);
        glBegin(GL_POLYGON);
        for (int j = 0; j < 360; j++) {
            auto angle = (GLfloat) (j * pi / 180);
            GLfloat x2 = (GLfloat) x1 + (3 * cos(angle));
            GLfloat y2 = (GLfloat) y1 + (3 * sin(angle));
            glVertex2f(x2, y2);
        }
        glEnd();
    }
    glDisable(GL_BLEND);
}

void rain_animation_foreground() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.0, 0.0, 1.0, 0.7);
    for (int i = 0; i < 50; i++) {
        GLfloat x1 = returnRandomFloatBetween(-WINDOW_WIDTH/2, WINDOW_WIDTH/2);
        GLfloat y1 = returnRandomFloatBetween(-WINDOW_HEIGHT/2, WINDOW_HEIGHT/2);
        glBegin(GL_POLYGON);
        for (int j = 0; j < 360; j++) {
            auto angle = (GLfloat) (j * pi / 180);
            GLfloat x2 = (GLfloat) x1 + (3 * cos(angle));
            GLfloat y2 = (GLfloat) y1 + (3 * sin(angle));
            glVertex2f(x2, y2);
        }
        glEnd();
    }
    glDisable(GL_BLEND);
}

void goal_text() {
    if (is_player_scored) {
        if (player_scored == 1) {
            glColor3f(1.0, 0.0, 0.0);
        } else if (player_scored == 2) {
            glColor3f(0.0, 0.0, 1.0);
        }
        glRasterPos2f(-90, -5 - paddingTop/2);
        for (char i: goalTextString) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
        }
    }
}

void timeText() {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-40, WINDOW_HEIGHT / 2 - padding / 2 - 8);
    for (char i: "Time: ") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
    for (char i: intToString(current_second)) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
}

void scoreText() {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-WINDOW_WIDTH / 2 + padding / 2 + 8, WINDOW_HEIGHT / 2 - padding / 2 - 8);
    for (char i: "Score: ") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
    for (char i: intToString(player1.getPlayerScore())) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
    for (char i: " - ") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
    for (char i: intToString(player2.getPlayerScore())) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
}

void howToPlayText() {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WINDOW_WIDTH / 2 - padding / 2 - 250, WINDOW_HEIGHT / 2 - padding / 2 - 8);
    for (char i: "How To Play:") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WINDOW_WIDTH / 2 - padding / 2 - 250, WINDOW_HEIGHT / 2 - padding / 2 - 28);
    for (char j: "Player 1: W, S") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, j);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WINDOW_WIDTH / 2 - padding / 2 - 250, WINDOW_HEIGHT / 2 - padding / 2 - 48);
    for (char k: "Player 2: Up, Down") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, k);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WINDOW_WIDTH / 2 - padding / 2 - 250, WINDOW_HEIGHT / 2 - padding / 2 - 68);
    for (char l: "Press R to Rain") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, l);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WINDOW_WIDTH / 2 - padding / 2 - 250, WINDOW_HEIGHT / 2 - padding / 2 - 88);
    for (char m: "Press T to Snow") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, m);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WINDOW_WIDTH / 2 - padding / 2 - 250, WINDOW_HEIGHT / 2 - padding / 2 - 108);
    for (char n: "Press H to hide/show this") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, n);
    }
}

void drawInGameTexts() {
    scoreText();
    timeText();
    goal_text();
}

void drawMenuBackground() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0, 1.0, 1.0, 0.75);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glBindTexture(GL_TEXTURE_2D, textureName[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-WINDOW_WIDTH/2, -WINDOW_HEIGHT/2);
    glTexCoord2f(0.0, 1.0); glVertex2f(-WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    glTexCoord2f(1.0, 1.0); glVertex2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    glTexCoord2f(1.0, 0.0); glVertex2f(WINDOW_WIDTH/2, -WINDOW_HEIGHT/2);
    glEnd();

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
}

void drawMenuButtons() {
    for (Button button: menuButtons) {
        button.drawButton();
    }
}

void drawMenuButtonTexts() {
    for (Button button: menuButtons) {
        button.drawButtonText();
    }
}

void drawMenuTexts() {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-90, 200);
    for (char i: "The Glow Hockey") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WINDOW_WIDTH/2 - 400, -WINDOW_HEIGHT / 2 + padding / 2 + 8);
    for (char i: "By: ") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2f(WINDOW_WIDTH/2 - 350, -WINDOW_HEIGHT / 2 + padding / 2 + 8);
    for (char i: "Ayca Kiremitci") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WINDOW_WIDTH/2 - 190, -WINDOW_HEIGHT / 2 + padding / 2 + 8);
    for (char i: "and") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
    glColor3f(0.0, 0.0, 1.0);
    glRasterPos2f(WINDOW_WIDTH/2 - 140, -WINDOW_HEIGHT / 2 + padding / 2 + 8);
    for (char i: "Hazar Belge") {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
}

void drawMenu() {
    drawMenuBackground();
    drawMenuButtons();
    drawMenuButtonTexts();
    drawMenuTexts();
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
    glGenTextures( 9, textureName );
    for ( int i=0; i<9; i++ ) {
        glBindTexture(GL_TEXTURE_2D, textureName[i]);
        loadTextureFromFile(filenameArray[i]);
    }
    player1 = Player(1, player1X1, player1Y1, playerWidth, playerHeight, playerSpeed);
    player2 = Player(2, player2X1, player2Y1, playerWidth, playerHeight, playerSpeed);
}

void display() {
    if(gameStarted) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        drawPlayers();
        drawGoals();
        drawPitch();
        ball();
        if (isSnowyDay) snow_animation_foreground();
        if (isRainyDay) rain_animation_foreground();
        drawInGameTexts();
    } else {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        drawMenu();
    }
    if (showHowToPlay) {
        howToPlayText();
    }
    glFlush();
}

#endif //CO_OP_BALL_GAME_DISPLAY_H
