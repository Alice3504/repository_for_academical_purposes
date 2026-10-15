#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void func(float a[], float b[], int dim, float *dot_product, float *angle_cos)
{
	*dot_product = 0.0f;
	for (int i = 0; i < dim; i++)
	{
		*dot_product += (float)(a[i] * b[i]);
	}
	float norm_a = 0;
	float norm_b = 0;
	for (int i = 0; i < dim; i++)
	{
		norm_a += a[i] * a[i];
	}
	norm_a = sqrt(norm_a);
	for (int i = 0; i < dim; i++)
	{
		norm_b += b[i] * b[i];
	}
	norm_b = sqrt(norm_b);
	*angle_cos = *dot_product / (norm_a * norm_b);
	
	return;
}

int main(void)
{
	float a[] = {3, 4};
	float b[] = {10, 0};
	
	float dot_product;
	float angle_cos;

	void (*func_ptr) (float a[], float b[], int dim, float *dot_product, float *angle_cos) = func;
	
	func_ptr(a, b, 2, &dot_product, &angle_cos);
	
	printf("Скалярное произведение: %f, Косинус угла: %f\n", dot_product, angle_cos);
	
	return 0;
}
