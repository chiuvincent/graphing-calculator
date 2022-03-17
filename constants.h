#ifndef CONSTANTS_H
#define CONSTANTS_H
const float SCREEN_WIDTH = 750;
const float SCREEN_HEIGHT = 600;
const float WORK_PANEL = SCREEN_WIDTH*4/5;
const float SIDE_BAR = SCREEN_WIDTH*1/5;

const int MAX = 30;
const int SB_MOUSE_POSITION = 0;
const int SB_MOUSE_CLICKED = SB_MOUSE_POSITION + 1;
const int SB_KEY_PRESSED = SB_MOUSE_CLICKED + 1;
const int FUNCTION_CHOSEN = SB_KEY_PRESSED + 1;
#endif // CONSTANTS_H
