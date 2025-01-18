#include "csapp.h"
#define N 100

int main()
{
    int status, i;
    pid_t pid;
    pid_t pids[N];

    for (i = 0; i < N; i++) {
        if ((pid = Fork()) == 0) {  /* child */
            exit(100+i);
        }
        pids[i] = pid;
    }

    /* parent waits for all of its children to terminate */
    int fils = 0;
    while ((pid = waitpid(pids[fils++], &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("child %ld terminated normally with exit status=%d\n",
                   (long)pid, WEXITSTATUS(status));
        } else {
            printf("child %ld terminated abnormally\n", (long)pid);
        }
    }

    if (errno != ECHILD) {
        unix_error("waitpid error");
    }

    exit(0);
}