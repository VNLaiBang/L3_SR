#include "csapp.h"

int main() {
  char *env[] = {"PATH=/bin", NULL};
  if (Fork() == 0) {
     execlp("ls", "ls", "-lt", NULL, env);
  } else {
     wait(NULL);
  }
  exit(0);
}