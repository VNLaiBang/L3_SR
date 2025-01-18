#include "csapp.h"
#define N 20

int main()
{
    int status, i;
    pid_t pid;

    for (i = 0; i < N; i++) {
        if ((pid = Fork()) == 0) {  /* child */
            
            printf("1) child %ld launched at loop iteration %d\n",
                   (long)getpid(), i);
            printf("2) child %ld launched at loop iteration %d\n",
                   (long)getpid(), i);  
            printf("3) child %ld launched at loop iteration %d\n",
                   (long)getpid(), i);            
            exit(100+i);
        }
    }

    /* parent waits for all of its children to terminate */
    while ((pid = waitpid(-1, &status, 0)) > 0);

    if (errno != ECHILD) {
        unix_error("waitpid error");
    }

    exit(0);
}