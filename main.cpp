#include "manager.h"

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    #ifdef __APPLE_CC__
    glutInitWindowPosition(250, 250);
    #else
    glutInitWindowPosition(300, 150);
    #endif
    glutInitWindowSize((int)WINDOW_WIDTH, (int)WINDOW_HEIGHT);
    glutCreateWindow("The Ball Game");
    displayInit();
    glClearColor(0.0, 0.6, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-WINDOW_WIDTH/2, WINDOW_WIDTH/2, -WINDOW_HEIGHT/2, WINDOW_HEIGHT/2);
    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(special);
    glutSpecialUpFunc(specialUp);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMouseFunc(mouse);
    glutTimerFunc(1000, timer, current_second);
    glutMainLoop();
    return EXIT_SUCCESS;
}