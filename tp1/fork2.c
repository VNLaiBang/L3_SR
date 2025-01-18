#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {                                              
  pid_t pid = fork();                                           
                                                          
  if (pid == -1) { exit(-3);}                                                                             
  else if (pid > 0) {                                     
    printf("je suis le père, mon PID est %d\n", getpid());
    printf("je suis le père, le PID de mon père est %d\n", getppid());
  } else {                                                
    printf("je suis le fils, mon PID est %d\n", getpid());
    printf("je suis le fils, le PID de mon père est %d\n", getppid());
  }                                                       
}                                                         

