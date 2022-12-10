#include <stdio.h>
#include <stdlib.h>
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
	for (int i = 0; i < N; i++)
	{
		matrix[i] = malloc(N * sizeof(int));
	}

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
	
	printMatrix(matrix, N);

	printf("\n1 Square:\n");
	printf("\nSum: %d\n", sum(matrix, 0, 0, (N % 2 == 0) ? N / 2 : N / 2 + 1, (N % 2 == 0) ? N / 2 : N / 2 + 1));
	printf("Max: %d\n\n", maxValue(matrix, 0, 0, (N % 2 == 0) ? N / 2 : N / 2 + 1, (N % 2 == 0) ? N / 2 : N / 2 + 1));

	printf("2 Square:\n");
	printf("\nSum: %d\n", sum(matrix, 0, N / 2, (N % 2 == 0) ? N / 2 : N / 2 + 1, N));
	printf("Min: %d\n\n", minValue(matrix, 0, N / 2, (N % 2 == 0) ? N / 2 : N / 2 + 1, N));
	
	printf("3 Square\n");
	printf("\nSum: %d\n", sum(matrix, N / 2, 0, N, (N % 2 == 0) ? N / 2 : N / 2 + 1));
	printf("Honest Min: %d\n\n", honestMinValue(matrix, N / 2, 0, N, (N % 2 == 0) ? N / 2 : N / 2 + 1));
	
	printf("4 Square:\n");
	printf("\nSum: %d\n", sum(matrix, N / 2, N / 2, N, N));

	return 0;
}

int sum(int** matrix, int ys, int xs, int yf, int xf)
{
	int sum = 0;
	for (int y = ys; y < yf; y++)
	{
		for (int x = xs; x < xf; x++)
		{
			printf("%4d", matrix[y][x]);
			sum += matrix[y][x];
		}
		printf("\n");
	}
	return sum;
}

int maxValue(int** matrix, int ys, int xs, int yf, int xf)
{
	int maxValue = matrix[0][0];
	for (int y = ys; y < yf; y++)
		for (int x = xs; x < xf; x++)
			maxValue = (maxValue < matrix[y][x]) ? matrix[y][x] : maxValue;
	
	return maxValue;
}

int minValue(int** matrix, int ys, int xs, int yf, int xf)
{
	int minValue = 0;
	for (int y = ys; y < yf; y++)
		for (int x = xs; x < xf; x++)
			minValue = (minValue > matrix[y][x]) ? matrix[y][x] : minValue;

	return minValue;
}

int honestMinValue(int** matrix, int ys, int xs, int yf, int xf)
{
	int minValue = 0;
	for (int y = ys; y < yf; y++)
		for (int x = xs; x < xf; x++)
			if(matrix[y][x]%2==0)
				minValue = (minValue > matrix[y][x]) ? matrix[y][x] : minValue;

	return minValue;
}