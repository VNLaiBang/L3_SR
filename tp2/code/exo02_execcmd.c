#include "csapp.h"
extern char**environ;

int main(int argc, char **argv) {
    execv(argv[1], &argv[1]);
}