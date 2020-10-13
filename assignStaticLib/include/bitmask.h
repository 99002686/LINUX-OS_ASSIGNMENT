#ifndef __BITMASK_H
#define __BITMASK_H

#ifndef SET
#define SET     1
#endif

#ifndef RESET
#define RESET    0
#endif

int set(int, int*);
int reset(int, int*);
int flip(int, int*);
int query(int, int*);

#endif