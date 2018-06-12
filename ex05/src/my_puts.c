#include <stdio.h>
#include <string.h>

int my_puts (const char *str1){
  unsigned i;
  for (int i = 0; *(str1+i) != '\0'; i++){
   write(1,str1+i,1);
  }
   write(1,"\n",1);
  return 0;
}
