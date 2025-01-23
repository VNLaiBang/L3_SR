#include "csapp.h"

unsigned int remainingTime;

void handler_SIGINT(int sig) {
}

int main(int argc, char **argv) {
    Signal(SIGINT, handler_SIGINT);

    remainingTime = sleep(atoi(argv[1]));
    fprintf(stdout, "\nTime passed by sleep: %d\n", (atoi(argv[1]) - remainingTime));
    exit(0);

}