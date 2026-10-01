#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COUNT 200

void ChildProcess(void);
void ParentProcess(void); 

int main(void)
{
    pid_t pid;

    pid = fork();
	
    if(pid != 0)
	{
        ParentProcess();
        wait(NULL);
    }
	else
	{
        ChildProcess();
        exit(EXIT_SUCCESS);
    }
	return 0;
}

void ChildProcess(void)
{
    for (int i = 1; i <= MAX_COUNT; i++) {
        printf("This line is from child, value = %d\n", i);
    }
}

void ParentProcess(void)
{
    for (int i = 1; i <= MAX_COUNT; i++) {
        printf("This line is from parent, value = %d\n", i);
    }
}
