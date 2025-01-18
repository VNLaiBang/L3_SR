#include "csapp.h"

int main() {
  if (Fork() != 0) {
    printf("je suis le père, mon PID est %d\n", getpid());
    sleep(10);  /* blocage pendant 10 secondes */
    exit(0);
  } else {
    printf("je suis le fils, mon PID est %d\n", getpid());
    sleep(10);  /* blocage pendant 10 secondes */
    exit(0);
  }
}