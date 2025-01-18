#include "csapp.h"

int main() 
{
    pid_t pid = Fork();

    if (pid == 0) {  /* child */
        exit(0);
    } else {
        int status;
        status = wait(&pid);
        fprintf(stdout, "status = %d\n", status);

        status = wait(&pid);
        fprintf(stdout, "status = %d\n", status);
    }
}