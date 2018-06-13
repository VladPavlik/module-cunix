#include <stdio.h>
#include <stdlib.h>

int my_atoi (const char *nptr) {
  int rec = 0;
  int sign = 1;
  if (*nptr == '-') {
    sign = -1;
    nptr++;
}
for (;(*nptr >= '0')&&(*nptr <= '9')&&(*nptr != '\0');nptr++) {  
   rec = rec * 10;
   rec = rec + (*nptr - 48);
}
    return (sign*rec);
}
