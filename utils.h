#ifndef CO_OP_BALL_GAME_UTILS_H
#define CO_OP_BALL_GAME_UTILS_H

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Texture.h"
#include "manager.h"
#include <random>

std::string intToString(int value) {
    std::string str = std::to_string(value);
    return str;
}

void resetRandomSeedWith() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000000);
    srand(dis(gen));
}

GLfloat returnRandomFloatBetween(GLfloat min, GLfloat max) {
    resetRandomSeedWith();
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::uniform_real_distribution<GLfloat> uni(min, max);
    return uni(rng);
}

void line_loop(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void loadTextureFromFile(char *filename)
{
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    Texture theTexMap(filename );

    // Pixel alignment: each row is word aligned.  Word alignment is the default.
    // glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

    // Set the interpolation settings to best quality.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB,
                      (GLsizei)theTexMap.GetNumCols(), (GLsizei)theTexMap.GetNumRows(),
                      GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );
}

static GLuint textureName[9];

void texture_drawer(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, int textureIndex, GLfloat alpha=1) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(1.0, 1.0, 1.0, alpha);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glBindTexture(GL_TEXTURE_2D, textureName[textureIndex]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(x1, y1);
    glTexCoord2f(0.0, 1.0); glVertex2f(x1, y2);
    glTexCoord2f(1.0, 1.0); glVertex2f(x2, y2);
    glTexCoord2f(1.0, 0.0); glVertex2f(x2, y1);
    glEnd();

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
}

#endif //CO_OP_BALL_GAME_UTILS_H
