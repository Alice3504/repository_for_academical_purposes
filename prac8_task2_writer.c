#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_WTL "/tmp/fifo_wtl"
#define FIFO_LTW "/tmp/fifo_ltw"

int main()
{
	const char *messages[5] = {
		"hello",
		"mitochondria is the powerhouse of the cell",
		"qwerty",
		"your welcomm",
		"goodbye"
	};
	char buffer[80];

	int fd_in = open(FIFO_WTL, O_WRONLY);
	int fd_out = open(FIFO_LTW, O_RDONLY);
	
	for (int i = 0; i < 5; i++)
	{
		printf("Sending a message: %s\n", messages[i]);
		write(fd_in, messages[i], strlen(messages[i]));
		ssize_t bytes_read = read(fd_out, buffer, sizeof(buffer) - 1);
		if (bytes_read <= 0)
		{
			break;
		}
		buffer[bytes_read] = '\0';
		if (strcmp(buffer, "thank you") == 0)
		{
			printf("Thanks received. ");
		}
		if (i < 4)
		{
			printf("Onto the next message\n");
		}
		else
		{
			printf("That's all. Terminating\n");
		}
	}

	close(fd_in);
	close(fd_out);
	return 0;
}
