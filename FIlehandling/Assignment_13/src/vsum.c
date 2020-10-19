#include "myutils.h"

int vsum (int arg1, ...)
{
    va_list valist;
   int sum = 0;
   int i;
   /* initialize valist for num number of arguments */
   va_start(valist, arg1);
   /* access all the arguments assigned to valist */
   for (i = 0; i < arg1; i++) {
      sum += va_arg(valist, int);
   }
   /* clean memory reserved for valist */
   va_end(valist);
   return sum;
}