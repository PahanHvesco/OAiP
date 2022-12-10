#pragma once
#include <stdio.h>

int inputInteger()
{
	int value;
	while (scanf_s("%d", &value) != 1 && getchar() != '\n')
	{
		printf("Incorupted input x_x\n\n");
		rewind(stdin);
		printf("Input value: ");
	}
	return value;
}

int inputRestrictedInteger(int x1, int x2)
{
	int value;
	while (scanf_s("%d", &value) != 1 || value<x1 || value>x2 || getchar() != '\n')
	{
		printf("Incorupted input x_x\n\n");
		rewind(stdin);
		printf("Input value: ");
	}
	printf("\n");
	return value;
}

int inputMorePositiveInteger()
{
	int value;
	while (scanf_s("%d", &value) != 1 || value < 0 || getchar() != '\n')
	{
		printf("Incorupted input x_x\n\n");
		rewind(stdin);
		printf("Input value: ");
	}
	printf("\n");
	return value;
}

int inputMoreZeroInteger()
{
	int value;
	while (scanf_s("%d", &value) != 1 || value <= 0 || getchar() != '\n')
	{
		printf("Incorupted input x_x\n\n");
		rewind(stdin);
		printf("Input value: ");
	}
	printf("\n");
	return value;
}

int hgh(int value)
{
	for (int i = 1; i != value; i *= 2)
		if (i > value)
		{
			return i;
			break;
		}
}