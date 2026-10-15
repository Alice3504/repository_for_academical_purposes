#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **array_ptr;
	array_ptr = (int**) calloc(4, sizeof(int*));
	
	for (int i = 0; i < 4; i++)
	{
		array_ptr[i] = (int*) calloc(4, sizeof(int));
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("Address of the (%d, %d) element: %p\n",
				i, j, &array_ptr[i][j]);
		}
	}
	
	return 0;
}
