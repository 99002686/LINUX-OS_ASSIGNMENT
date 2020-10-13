#include "bitmask.h"

int set(int pin, int *bit)
{
    return (bit[pin] = SET);
}

