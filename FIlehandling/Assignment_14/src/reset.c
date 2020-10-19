#include "bitmask.h"

int reset (int pin, int *bit)
{
    bit[pin] = RESET;
    return bit[pin];
}

