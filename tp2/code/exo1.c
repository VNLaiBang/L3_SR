#include "csapp.h"
extern char**environ;

int main(int argc, char **argv, char **envp) {
    fprintf(stdout, "PID: %d", getpid());
    int i = 0;
    while (environ[i] != NULL) {
        fprintf(stdout, "%s\n", environ[i++]);
    }
}