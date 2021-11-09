#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>


void stop() {
    exit(0);
}

int main() {
    char devpath[] = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int keyboard = open(devpath, O_RDONLY);
    struct input_event e;
    FILE* output = fopen("ex2.txt", "w");
    signal(SIGINT, stop);
         
    while (free)
    {
        read(keyboard, &e, sizeof(e));

        if (e.type == 1)
        {
            if (e.value == 1) {
                fprintf(output, "PRESSED %x (%d)\n", e.code, e.code);
            } else if (e.value == 0) {
                fprintf(output, "RELEASED  %x (%d)\n", e.code, e.code);
            }
            fflush(output);
        }
    }
}