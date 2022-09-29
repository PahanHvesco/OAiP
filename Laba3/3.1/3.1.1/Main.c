#include <stdio.h>
#define N 10

void main(void)
{
	int array[N], A, B;

	//fillArray(array, N);
	randArray(array, N);
	
	do
	{
		printf("Enter the range (from A to B): ");
		if (scanf_s("%i%i", &A, &B) != 2 || A<0 || B<0)
		{
			printf("Error\n");
			fgetc(stdin);
			continue;
		}

		int Iter = 0;
		for (int i = 0; i < N; i++)
		{
			if (array[i] >= A && array[i] <= B)Iter++;
		}

		int sum = sumArray(array, N) - sumArray(array, indexArray(array, N, maxInArray(array, N))+1);

		printf("Sum of array elements: %d\n", sum);
		printf("Number of elements: %d\n", Iter);
		break;
	} while (1);
	return 0;
}