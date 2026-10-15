#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define READ  0
#define WRITE 1

int main() {
    int fd[2];
    ssize_t bytesRead;
    char buffer[128];

    pipe(fd);

    if (fork() == 0) {
        close(fd[READ]);
		
		for (int i = 1; i <= 9; i++)
		{
			printf("Number sent by child: %d\n", i);
			snprintf(buffer, 20, "%d", i);
			write(fd[WRITE], buffer, strlen(buffer) + 1);
			sleep(1);
		}
        close(fd[WRITE]);
    } else {
        close(fd[WRITE]);

        while (1)
		{
			bytesRead = read(fd[READ], buffer, sizeof(buffer) - 1);
			if (bytesRead <= 0)
			{
				break;
			}
            buffer[bytesRead] = '\0';
            printf("Number received by parent: %s\n", buffer);
        }

        close(fd[READ]);
        wait(NULL);
    }
    return 0;
}
