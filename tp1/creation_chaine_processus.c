#include "csapp.h"
#define N 4

int main() 
{
    fprintf(stdout, "pid = %d\nppid = %d\n", getpid(), getppid());

    int i;
    pid_t pid = 0;

    for (i = 0; i < N; i++) {
        pid = Fork();
        if (pid != 0) {
            wait(&pid);
        } else {
            fprintf(stdout, "pid = %d\nppid = %d\n", getpid(), getppid());
            exit(0);
        }
    }
}