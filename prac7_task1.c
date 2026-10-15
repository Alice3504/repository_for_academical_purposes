#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void on_ctrl_c(int signum);
void on_alarm(int signum);

void on_ctrl_c(int signum)
{
	printf("Нажатие ctrl+c произошло\n");
	kill(getpid(), SIGSTOP);
}

void on_alarm(int signum)
{
	printf("Процесс всё ещё работает\n");
}

int main()
{
	signal(SIGINT, on_ctrl_c);
	signal(SIGALRM, on_alarm);
	
	while (1)
	{
		sleep(1);
		alarm(1);
	}
}
