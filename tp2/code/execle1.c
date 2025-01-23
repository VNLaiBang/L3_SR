#include "csapp.h"

int main() {
  char *env[] = {"PATH=/bin", NULL};
  execle("ls", "ls", "-lt", NULL, env);
}
