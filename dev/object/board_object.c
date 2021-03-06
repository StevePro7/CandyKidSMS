#include "board_object.h"

// Navigate all 8x exits clockwise.
const unsigned char board_exitX[] = { 4, 9, 12, 12, 9, 4, 1, 1 };
const unsigned char board_exitY[] = { 1, 1, 4, 9, 12, 12, 9, 4 };

// Order: Pro, Adi, Suz, Kid.
const unsigned char board_homeX[] = { 10, 3, 10, 3 };
const unsigned char board_homeY[] = { 10, 10, 3, 4 };