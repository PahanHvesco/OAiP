#include <stdio.h>
#include "Header.h"

int main()
{
	int **matrix, *charakterArray, N;
	do
	{
		printf("Enter the size of the array(N>0): ");
		if (scanf_s("%d", &N) != 1 || N<=0)
		{
			printf("Error(-_-)\n\n");
			rewind(stdin);
			continue;
		}
		break;
	} while (1);

	charakterArray = malloc(N * sizeof(int*));
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
	charakter(matrix, charakterArray, N);
	printMatrixWithCharakter(matrix, charakterArray, N);
	sortMatrix(matrix, charakterArray, N);
	printf("\n\nChange matrix:\n");
	printMatrixWithCharakter(matrix, charakterArray, N);
	return 0;
}

int charakter(int** matrix, int* charakterArray, int n)
{
	for (int y = 0; y < n; y++)
	{
		int sum = 0;
		for (int x = 0; x < n; x++)
		{
			if (matrix[y][x] < 0 && matrix[y][x] % 2 == 0)
				sum += matrix[y][x];
		}
		charakterArray[y] = sum;
	}
}

int printMatrixWithCharakter(int** matrix, int* charakterArray, int n)
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			printf("%3d ", matrix[y][x]);
		}
		printf("| %3d\n", charakterArray[y]);
	}
}

int sortMatrix(int** matrix, int* charakterArray, int n)
{
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int i2 = 0; i2 < n; i2++)
		{
			if (charakterArray[i1] > charakterArray[i2])
			{
				int charakter = charakterArray[i1];
				charakterArray[i1] = charakterArray[i2];
				charakterArray[i2] = charakter;
				int* buf = matrix[i1];
				matrix[i1] = matrix[i2];
				matrix[i2] = buf;
			}
		}
	}
}