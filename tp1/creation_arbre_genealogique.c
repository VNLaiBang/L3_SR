#include "csapp.h"
#define N 3

int main() 
{
    char p[N] = "\0";
    fprintf(stdout, "pid = %d\nppid = %d\n", getpid(), getppid());

    int i;
    pid_t pid = 0;
    for (i = 0; i < N; i++) {
        pid = Fork();
        if (pid != 0) {
            wait(&pid);
        } else {
            p[0] = '-';
            p[1] = '\0';
            fprintf(stdout, "%s pid = %d\n%s ppid = %d\n",p, getpid(), p, getppid());
            if (i == 0) {
                for(i = 0; i < N; i++) {
                    pid = Fork();
                    if (pid != 0) {
                        wait(&pid);
                    } else {
                        p[1] = '-';
                        p[2] = '\0';
                        fprintf(stdout, "%s pid = %d\n%s ppid = %d\n", p, getpid(), p, getppid());
                        exit(0);
                    }
                }
            }
            exit(0);
        }
    }
}