#include <stdio.h>
#include <stdlib.h>


void print_left_half_pyramid(int *n) {
    int width = 2 * *n - 1; 
    
    for (int i = 1; i <= *n; i++) {
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}


void print_rotated_pyramid(int *n) {    
    for (int i = 1; i <= *n / 2; i++) {
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }

    for (int j = 1; j <= *n / 2 + 1; j++)
        printf("*");
    printf("\n");

    for (int i = *n / 2 + 1; i <= *n; i++) {
        for (int j = 1; j <= *n - i; j++)
            printf("*");
        printf("\n");
    }
}


void print_rectangle(int *n) {
    int width = 2 * *n - 1; 
    
    for (int i = 1; i <= *n; i++) {
        for (int j = 1; j <= width; j++) 
            printf("*");
        printf("\n");
    }
}



int main(int argc, char *argv[]) {
    int type, n;

    printf("Select type of figure:\n\n 1 — Left half of pyramid\n\n 2 — Rotated pyramid\n\n 3 — Rectangle\n\n");
    scanf("%d", &type);

    if (type < 1 || type > 3) {
        printf("\nWrong type of figure!");
        return 1;
    } else {
        printf("\nEnter number of rows: ");
        scanf("%d", &n);

        if (type == 1)
            print_left_half_pyramid(&n);
        else if (type == 2)
            print_rotated_pyramid(&n);
        else
            print_rectangle(&n);
    }

    return 0;
}