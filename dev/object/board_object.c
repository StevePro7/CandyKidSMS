#include "board_object.h"

// Navigate all 8x exits clockwise.
const unsigned char board_exitX[] = { 4, 9, 12, 12, 9, 4, 1, 1 };
const unsigned char board_exitY[] = { 1, 1, 4, 9, 12, 12, 9, 4 };

// Order: Kid, Pro, Adi, Suz.
const unsigned char board_homeX[] = { 3, 10, 3, 10 };
const unsigned char board_homeY[] = { 3, 10, 10, 3 };