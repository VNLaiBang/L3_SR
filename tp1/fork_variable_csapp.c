#include "csapp.h"

int main()                         // début du processus "main"
{                                  //    |
  pid_t pid;                       //    |
  int x = 1;                       //    |       x est une variable dans "main"
                                   //    |
  pid = Fork();                    //    |____   création d'un processus fils,
                                   //    |    |  à partir d'ici *deux processus* s'exécutent
  if (pid == 0) {  /* child */     //         |  pour "main" fork retourne > 0
    printf("child : x=%d\n", ++x); //         |  code exécuté par le processus fils
    exit(0);                       //         |  terminaison du fils
  }
                                   //    |       code exécuté par "main"
  /* parent */                     //    |
  printf("parent: x=%d\n", --x);   //    |       terminaison du processus "main"
  exit(0);
}
