#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void handler_ctrl_c(int signum);
void clear_fifos();

#define FIFO_WTL "/tmp/fifo_wtl"
#define FIFO_LTW "/tmp/fifo_ltw"

int main()
{
	char *thank_you = "Thank you";
	char buffer[80];

	mkfifo(FIFO_WTL, 0640);
	mkfifo(FIFO_LTW, 0640);
	int fd_out = open(FIFO_WTL, O_RDONLY);
	int fd_in = open(FIFO_LTW, O_WRONLY);
	
	signal(SIGINT, handler_ctrl_c);
	
	while (1)
	{
		ssize_t bytes_read = read(fd_out, buffer, sizeof(buffer) - 1);
		if (bytes_read <= 0)
		{
			break;
		}
		buffer[bytes_read] = '\0';
		printf("Listener has received a message: %s\n", buffer);
		write(fd_in, thank_you, strlen(thank_you));
	}

	clear_fifos();
	return 0;
}

void clear_fifos()
{
	unlink(FIFO_WTL);
	unlink(FIFO_LTW);
}

void handler_ctrl_c(int signum)
{
	clear_fifos();
	printf("\nFIFOs have been cleared\n");
	_exit(0);
}
