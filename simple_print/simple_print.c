#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
    int pid = fork();
    int status;
    printf ("Hello from process %s\n", (pid != 0)? "parent" : "child");
    if (pid > 0) waitpid(pid, &status, 0);
    return 0;
}
