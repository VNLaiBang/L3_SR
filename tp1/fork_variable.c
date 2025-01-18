#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {                                              
  pid_t pid;                                              
  int x = 1;

  pid = fork();                                                                                    
  if (pid == -1) { exit(-3);}                                                                                   
  else if (pid > 0) {                                     
    printf("père, x=%d\n", --x);
  } else {                                               
    printf("fils, x=%d\n", ++x);
  }                                                       
}  