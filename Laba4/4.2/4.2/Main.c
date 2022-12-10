#include <stdio.h>
#include "Header.h"

int main()
{
	int** matrix, N;
	do
	{
		printf("Enter the size of the array(N>0): ");
		if (scanf_s("%d", &N) != 1 || N <= 0)
		{
			printf("Error(-_-)\n\n");
			rewind(stdin);
			continue;
		}
		break;
	} while (1);

	matrix = malloc(N * sizeof(int*));
	for (int i = 0;i < N; i++)
		matrix[i] = malloc(N * sizeof(int));

	do
	{
		int value;
		printf("\n1. Fill matrix\n2. Rand matrix\nYour choice: ");
		if (scanf_s("%d", &value) != 1 || value < 1 || value>2)
		{
			printf("Error(-_-)\n\n");
			continue;
		}
		else if (value == 1)
		{
			fillMatrix(matrix, N);
			break;
		}
		else if (value == 2)
		{
			randMatrix(matrix, N);
			break;
		}
	} while (1);
	
	printf("\nYour matrix:\n");
	printMatrix(matrix, N);

	int value = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (matrix[y][x] < 0)
			{
				value++;
				break;
			}
		}
	}
	if (value == N)
		MultiplyingMatrixByNumber(matrix, N, -1);
	printf("\nChang matrix:\n");
	printMatrix(matrix, N);
	return 0;
}