#include "bitmask.h"

int flip(int pin, int *bit)
{
    return (bit[pin] ^= 1);
} 