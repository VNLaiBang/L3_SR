#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {                                              // début du processus "main"
  pid_t pid;                                              // |
                                                          // |
  pid = fork();                                           // |___ création d'un fils
                                                          // |   
  if (pid == -1) { exit(-3);}                             // |     création échouée
                                                          // |   | deux processus en exécution  
  else if (pid > 0) {                                     // |     test OK pour main = père
    printf("je suis le père, mon PID est %d\n", getpid());// |     exécuté par le père     
  } else {                                                //     | test OK pour le fils 
    printf("je suis le fils, mon PID est %d\n", getpid());//     | exécuté par le fils
  }                                                       // |   |
}                                                         // |   | terminaison de processus    

