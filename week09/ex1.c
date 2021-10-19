#include <stdlib.h>
#include <stdio.h>


struct frame {
    int age;
    int page_num;
};


struct frame * frames;
FILE *input;
long hit = 0, miss = 0;
long f_num;
const long num = 1 << 7;


void update_frames(int next_page) {
    int m = 0;
    for (int i = 0; i < f_num; i++) {
        if (frames[i].page_num == -1) {
            m = i;
            break;
        }
        else if (frames[i].age < frames[m].age)
            m = i;
        frames[i].age >>= 1;
    }

    for (int i = 0; i < f_num; i++) {
        if (frames[i].page_num == next_page) {
            frames[i].age |= num;
            hit += 1;
            return;
        }
    }
    miss += 1;
    frames[m].age = num;
    frames[m].page_num = next_page;
}


int main() {
    scanf("Type number of page frames: %ld", &f_num);

    frames = malloc(sizeof(struct frame) * f_num);
    
    for (int i = 0; i < f_num; i++) {
        frames[i].page_num = -1;
        frames[i].age = 0;
    }
    
    input = fopen("input.txt", "r");

    int next_page;
    while (fscanf(input, "%d", &next_page) != EOF)
        update_frames(next_page);
    
    free(frames);

    printf("Hits: %ld\n", hit);
    printf("Misses: %ld\n", miss);
    printf("Hits/Misses: %f\n", (double)hit/miss);
}
