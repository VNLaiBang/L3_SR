#include "csapp.h"
extern char**environ;

int main(int argc, char **argv, char **envp) {
    putenv("LANG=fr_FR");
    putenv("MANPAGER=less -X");
    
    execlp("man", argv[1], argv[2], NULL);
}