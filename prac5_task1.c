#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *array_ptr;
	array_ptr = (int*) calloc(4, sizeof(int));
	
	printf("Address of the first element: %p\n", &array_ptr[0]);
	printf("Address of the second element: %p\n", &array_ptr[1]);
	printf("Address of the third element: %p\n", &array_ptr[2]);
	printf("Address of the fourth element: %p\n", &array_ptr[3]);
	
	return 0;
}
