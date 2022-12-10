#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
			printf("%4.d ", matrix[y][x]);
		printf("\n");
	}
	printf("\n");
}

void fillMatrix(int** matrix, int row, int col)
{
	printf("1.Random matrix\n2.Fill matrix\nYour choice: ");
	int value = inputRestrictedInteger(1, 2);
	if (value == 1)
		randMatrix(matrix, row, col);
	else if (value == 2)
		inputMatrix(matrix, row, col);
}

int randMatrix(int** matrix, int row, int col)
{
	for (int y = 0; y < row; y++)
		for (int x = 0; x < col; x++)
			matrix[y][x] = rand()%200-100;
}

int inputMatrix(int** matrix, int row, int col)
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
	if (*row == *col)
	{
		for (int y = 0; y < *row; y++)
			for (int x = 0; x < *col; x++)
				if (y == x)
					for (int x2 = x; x2 < *row - 1; x2++)
						matrix[y][x2] = matrix[y][x2 + 1];
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
		matrix[i] = malloc(colSize * sizeof(int));
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
			printf("%d ", matrix[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

void QuickSortForMatrix(int** matrix, int row, int start, int finish)
{
	
	int leftFlag = start;
	int rightFlag = finish;
	int sr = (start + finish) / 2;
	do
	{
		while (sumElements(matrix, row, leftFlag) < sumElements(matrix, row, sr))
		{
			leftFlag++;
		}
		while (sumElements(matrix, row, rightFlag) > sumElements(matrix, row, sr))
		{
			rightFlag--;
		}
		if (leftFlag <= rightFlag)
		{
			if((leftFlag+1)%2 == 0 && (rightFlag-1)%2 == 0)
				copyElements(matrix, row, leftFlag, rightFlag);
			
			leftFlag++;
			rightFlag--;
		}
	} while (leftFlag <= rightFlag);
	if (leftFlag < finish)
	{
		QuickSortForMatrix(matrix, row, leftFlag, finish);
	}
	if (rightFlag > start)
	{
		QuickSortForMatrix(matrix, row, start, rightFlag);
	}
}

int sumElements(int** matrix, int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
		sum += matrix[i][col];
	return sum;
}

int copyElements(int** matrix, int row, int col1, int col2)
{
	for (int i = 0; i < row; i++)
	{
		int bufValue = matrix[i][col1];
		matrix[i][col1] = matrix[i][col2];
		matrix[i][col2] = bufValue;
	}
}