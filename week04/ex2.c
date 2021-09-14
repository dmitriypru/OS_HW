#include <stdio.h>
#include <stdlib.h>

/*

By fork every child process creates new child process. Tree will get bigger after increasing of count of loops

*/


int main() {
    for (int i = 0; i < 5; i++) {
        fork();
        sleep(5);
    }
    return 0;
}