#include <stdio.h>
#include <stdlib.h>

/*

We get different PIDs because we create new processess and all of them get different IDs

*/

int main() {
    int pid = fork();
    
    printf("Hello from parent %d\n", getppid());
    printf("Hello from child %d\n\n", getpid());

    return 0;
}