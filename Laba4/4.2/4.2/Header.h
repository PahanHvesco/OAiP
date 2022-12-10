#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printMatrix(int** array, int n);
int randMatrix(int** array, int n);

int printMatrix(int** array, int n)
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			printf("%3d ", array[y][x]);
		}
		printf("\n");
	}
}

int randMatrix(int** array, int n)
{
	srand(time(NULL));
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			array[y][x] = rand() % 200 - 100;
		}
	}
}

int fillMatrix(int** array, int n)
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			do
			{
				printf("[%d][%d]: ", y, x);
				if (scanf_s("%d", &array[y][x]) != 1)
				{
					continue;
				}
				break;
			} while (1);
		}
	}
}

int MultiplyingMatrixByNumber(int** matrix, int n, int number)
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			matrix[y][x] *= number;
		}
	}
}