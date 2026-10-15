#include <stdio.h>

void never_call(void)
{
	printf("How did you manage to call this?");
	return;
}

int main()
{
	printf("Congrats on running this code!");
	return 0;
}
