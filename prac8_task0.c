#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int fd[2];

    pipe(fd);

    if (fork() == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", (char *)NULL);
        perror("execlp ls");
        _exit(2);
    } else {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", "-l", (char *)NULL); 
        perror("execlp wc");
        _exit(3);
    }

    return 0;
}
