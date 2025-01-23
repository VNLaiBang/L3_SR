#include "csapp.h"

unsigned int remainingTime;

void handler_SIGINT(int sig) {
    fprintf(stdout, "\nSignal number: %d\n", sig);
}

void handler_SIGSTOP(int sig) {
    fprintf(stdout, "\nSignal number: %d\n", sig);
}

void handler_SIGTSTP(int sig) {
    fprintf(stdout, "\nSignal number: %d\n", sig);
}

int main(int argc, char **argv) {
    Signal(SIGINT, handler_SIGINT);
    Signal(SIGTSTP, handler_SIGTSTP);
    // Signal(SIGSTOP, handler_SIGSTOP); => Invalid argument
    pause(); // => Se stop pas apres avoir recu un signal
    fprintf(stdout, "Hello\n");
    exit(0);
}