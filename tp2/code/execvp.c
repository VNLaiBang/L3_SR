#include<stdio.h>
#include<unistd.h>

#define MAX 5

int main() {
   char *argv[MAX];
   argv[0] = "ls"; argv[1] = "-lt"; argv[2] = "/"; argv[3] = NULL;
   execvp("ls", argv);
}
