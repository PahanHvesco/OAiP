#include<stdio.h>

int main(void)
{
	do
	{
		int N;
		printf("Enter the Fibonacci number(N>1): ");
		if(!scanf_s("%d", &N)) printf("You entered something wrong\n\n");
		else
		{	
			if (N <= 1)
			{
				printf("N should be >1\n\n");
				continue;
			}
			int value1 = 0, value2 = 1, K;
			for (K=1; N!=value2 && N > value2; K++)
			{
				int value = value1;
				value1 = value2;
				value2 += value;
			}
			if (value2 != N) printf("The number %d is not a Fibonacci number!!!\n\n", N);
			else
			{
				printf("%d the ordinal number of the number %d\n\n", K, N);
				break;
			}
		}
		fgetc(stdin);
	}
	while (1);
	return 0;
}