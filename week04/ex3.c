#include <stdio.h>
#include <stdlib.h>


int main() {
    char str[256];
    scanf("%s", &str);

    int pid;
    pid = fork();
    if (pid == 0) {
        char *args[] = {str, NULL};
        execvp(str, args);
    }

    return 0;
}