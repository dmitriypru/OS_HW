#include <stdio.h>
#include <string.h>

int main()
{
   char str[255];
   gets(str);
   for (int i = strlen(str); i >= 0; i--) {
    printf("%c", str[i]);
   }
   
   return 0;
}