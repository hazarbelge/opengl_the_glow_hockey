#include "manager.h"

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, 250);
    glutInitWindowSize((int)WINDOW_WIDTH, (int)WINDOW_HEIGHT);
    glutCreateWindow("The Ball Game");
    glClearColor(0.0, 0.75, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-WINDOW_WIDTH/2, WINDOW_WIDTH/2, -WINDOW_HEIGHT/2, WINDOW_HEIGHT/2);
    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(special);
    glutSpecialUpFunc(specialUp);
    displayInit();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutTimerFunc(1000, timer, current_second);
    glutMainLoop();
    return EXIT_SUCCESS;
}