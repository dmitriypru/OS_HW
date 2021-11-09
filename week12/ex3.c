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
    FILE * output = fopen("ex3.txt", "w");
    int a, c, e, p,
    signal(SIGINT, stop);

    fprintf(output, "There are following shortcuts:\nC A P\nP E\nA E\n\n");

    while (free) {
        read(keyboard, & e, sizeof(e));
        if (e.type == EV_KEY) {
            if (e.value == 0) {
                switch (e.code) {
                case KEY_A:
                    a = 0;
                    break;
                case KEY_C:
                    c = 0;
                    break;
                case KEY_E:
                    e = 0;
                    break;
                case KEY_P:
                    p = 0;
                    break;
                }
            } else if (e.value == 1) {
                switch (e.code) {
                case KEY_A:
                    a = 1;
                    break;
                case KEY_C:
                    c = 1;
                    break;
                case KEY_E:
                    e = 1;
                    break;
                case KEY_P:
                    p = 1;
                    break;
                }
            }

            if (p && e)
                fprintf(output, "I passed the Exam!\n");
            else if (c && a && p)
                fprintf(output, "Get some cappuccino!\n");

            else if (a && e)
                fprintf(output, "Another example\n");

            fflush(output);
        }
    }
}