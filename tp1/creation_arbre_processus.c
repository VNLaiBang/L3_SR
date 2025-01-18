#include "csapp.h"
#define N 4

int main() 
{
    int i;
    pid_t pid;
    char p[N] = "\0";

    for (i = 0; i < N; i++) {
        p[i] = '-'; 
        p[i+1] = '\0'; 
        pid = Fork();
        if (pid != 0) {
            fprintf(stdout, "%s pid = %d\n%s ppid = %d\n", p, getpid(), p, getppid());
            exit(0);
        }
    }
}