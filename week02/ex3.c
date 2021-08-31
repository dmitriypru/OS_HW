#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    int width = 2*n - 1; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= width; j++) {
            if (j >= width/2 - i + 2 && j <= width/2  + i) 
                printf("*");
            else 
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}