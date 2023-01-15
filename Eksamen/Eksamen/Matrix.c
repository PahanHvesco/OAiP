#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
	c
	o
	l
row 1 1 1
    1 1 1
	1 1 1
*/

int** createMatrix(int row, int col)
{
	int** Matrix;
	Matrix = malloc(col * sizeof(int*));
	for (int i = 0; i < col; i++)
		Matrix[i] = malloc(row * sizeof(int));
	return Matrix;
}

void randMatrix(int** Matrix, int row, int col)
{
	for (int y = 0; y < col; y++)
	{
		for (int x = 0; x < row; x++)
		{
			Matrix[y][x] = rand() % 101;
		}
	}
}

void printMatrix(int** Matrix, int row, int col)
{
	printf("\n");
	for (int y = 0; y < col; y++)
	{
		for (int x = 0; x < row; x++)
		{
			printf("%5.d", Matrix[y][x]);
		}
		printf("\n");
	}
}

void coppyCol(int** Matrix, int col, int row1, int row2)
{
	for (int i = 0; i < col; i++)
	{
		int bufInt = Matrix[i][row1];
		Matrix[i][row1] = Matrix[i][row2];
		Matrix[i][row2] = bufInt;
	}
}

void coppyRow(int** Matrix, int row, int col1, int col2)
{
	for (int i = 0; i < row; i++)
	{
		int bufInt = Matrix[col1][i];
		Matrix[col1][i] = Matrix[col2][i];
		Matrix[col2][i] = bufInt;
	}
}

int sumRow(int** Matrix, int sum_row, int col)
{
	int sum = 0;
	for (int i = 0; i < col; i++)
	{
		sum += Matrix[i][sum_row];
	}
	return sum;
}

int sumCol(int** Matrix, int row, int sum_col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		sum += Matrix[sum_col][i];
	}
	return sum;
}

void deleteIndexRow(int** Matrix, int row, int* col, int IndexCol)
{
	for (int i = IndexCol; i < *col-1; i++)
	{
		coppyRow(Matrix, row, i, i + 1);
	}
	*col = *col-1;
	Matrix = realloc(Matrix, *col * sizeof(int*));
}

void deleteIndexCol(int** Matrix, int* row, int col, int IndexRow)
{
	for (int x = IndexRow; x < *row-1; x++)
	{
		coppyCol(Matrix, col, x, x + 1);
	}
	*row = *row - 1;
	for (int i = 0; i < col; i++)
	{
		Matrix[i] = realloc(Matrix[i], *row * sizeof(int*));
	}
}