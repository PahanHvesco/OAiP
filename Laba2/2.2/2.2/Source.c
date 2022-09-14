#include<stdio.h>

int main(void)
{
	do
	{
		int m, n;

		printf("Enter value M and N(M<N): ");

		if (scanf_s("%i%i", &m, &n) == 2)
		{
			m = (m < 0) ? m * (-1) : m;
			n = (n < 0) ? n * (-1) : n;

			if (m < n)
			{
				float x = 0;
				for (int i = 0; i < n; i++)
				{
					x += 1.0 / (m + i);
				}
				printf("Result: %f\n\n", x);
				return 0;
			}
		}
		printf("You entered something wrong!!!\n\n");
		rewind(stdin);
	} 
	while (1);
	return 0;
}