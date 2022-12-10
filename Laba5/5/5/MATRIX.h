#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** initMatrix(int row, int col);
void printMatrix(int** matrix, int row, int col);


int** initMatrix(int row, int col)
{
	int** matrix; 
	matrix = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		matrix[i] = (int*)malloc(col * sizeof(int));
	}
	return matrix;
}

void printMatrix(int** matrix, int row, int col)
{
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
			printf("%3.d ", matrix[y][x]);
		printf("\n");
	}
	printf("\n");
}

void fillMatrix()
{

}

void randMatrix(int** matrix, int row, int col)
{
	for (int y = 0; y < row; y++)
		for (int x = 0; x < col; x++)
			matrix[y][x] = rand()%200-100;
}

void inputMatrix(int** matrix, int row, int col)
{
	for (int y = 0; y < row; y++)
		for (int x = 0; x < col; x++)
		{
			printf("[%d][%d]: ", y, x);
			matrix[y][x] = inputInteger();
		}
}

void deleteMainDiagonal(int** matrix, int *row, int *col)
{
	if (*row != *col)
	{
		
	}
	else
	{
		for (int y = 0; y < *row; y++)
		{
			for (int x = 0; x < *col; x++)
				if (y == x)
				{
					for (int x2 = x; x2 < *row - 1; x2++)
						matrix[y][x2] = matrix[y][x2 + 1];
				}
		}
		*col -= 1;
	}
}

void deleteSpesialRowK(int** matrix, int* row, int K)
{
	int matrixRow = *row;
	for (int y = K - 1; y < *row; y += K)
	{
		matrixRow--;
		for (int x = 0; matrix[y][x] != -100; x++)
		{
			matrix[y][x] = NULL;
		}
	}
	for (int y1 = 0; y1 < *row; y1++)
	{
		if (matrix[y1][0] == NULL)
		{
			for (int y2 = y1; y2 < *row-1; y2++)
			{
				matrix[y2] = matrix[y2 + 1];
			}
		}
	}
	*row = matrixRow;
}

int** spesialMatrix(int row)
{
	int** matrix = malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		printf("Col %d: ", i+1);
		int colSize = inputMoreZeroInteger() + 1;
		matrix[i] = (int *)malloc(colSize * sizeof(int));
		matrix[i][colSize - 1] = -100;

		for (int x = 0; x < colSize - 1; x++)
		{
			matrix[i][x] = rand() % 200 - 100;
		}
	}
	return matrix;
}

void printSpesialMatrix(int** matrix, int row)
{
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; matrix[y][x] != -100; x++)
		{
			printf("%4.d ", matrix[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

void freeMatrix(int** matrix, int row)
{
	for (int i = 0; i < row; i++)
		free(matrix[i]);
	free(matrix);
}