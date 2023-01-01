#ifndef CO_OP_BALL_GAME_KEYBOARD_H
#define CO_OP_BALL_GAME_KEYBOARD_H

void special(int key, [[maybe_unused]] int x, [[maybe_unused]] int y)
{
    keyStates[key] = true;
}

void specialUp(int key, [[maybe_unused]] int x, [[maybe_unused]] int y)
{
    keyStates[key] = false;
}

void keyboard(unsigned char key, [[maybe_unused]] int x, [[maybe_unused]] int y)
{
    switch (key) {
        case 'r':
            isRainyDay = !isRainyDay;
            break;
        case 't':
            isSnowyDay = !isSnowyDay;
            break;
        case 'h':
            showHowToPlay = !showHowToPlay;
            break;
        default:
            keyStates[key] = true;
            break;
    }
}

void keyboardUp(unsigned char key, [[maybe_unused]] int x, [[maybe_unused]] int y)
{
    keyStates[key] = false;
}

#endif //CO_OP_BALL_GAME_KEYBOARD_H
