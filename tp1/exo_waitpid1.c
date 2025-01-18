#include "csapp.h"

int main()
{
    pid_t pid;
    pid_t pids[2];
    for (int i = 0; i < 2; i++)
    {
        pid = Fork();
        if (pid == 0)
        { /* child */
            exit(100 + i);
        } else {
            fprintf(stdout, "fils pid = %d\n", pid);
        }
        pids[i] = pid;
    }

    int status;
    pid = waitpid(pids[0], &status, 0);
    fprintf(stdout, "status = %d\npid = %d\n", status, pid);

    pid = waitpid(pids[1], &status, 0);
    fprintf(stdout, "status = %d\npid = %d\n", status, pid);
}