#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

void bubleSort(int* array, int size)//���������� ���������
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (array[i] < array[j])
			{
				int bufInt = array[j];
				array[j] = array[i];
				array[i] = bufInt;
			}
}

void selectionSort(int* array, int size)//����������� �������
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i+1; j < size; j++)
			if (array[i] > array[j])
			{
				int bufInt = array[i];
				array[i] = array[j];
				array[j] = bufInt;
			}
	}
}

void insertionSort(int* array, int size)//���������� ���������
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i + 1;j >= 1; j--)
			if (array[j-1] > array[j])
			{
				int bufInt = array[j-1];
				array[j-1] = array[j];
				array[j] = bufInt;
			}
	}
}

void shellSort(int* array, int size)
{
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int pass = step; pass < size;pass++)
		{
			for (int replacment = pass - step; replacment >= 0 && array[replacment] > array[replacment + step]; replacment -= step)
			{
				int bufInt = array[replacment];
				array[replacment] = array[replacment+step];
				array[replacment+step] = bufInt;
			}
		}
	}
}

void margeSort(int* array, int size)
{
	int element = 2;
	int newSize = 0;
	for (int i = 1;; i *= 2)
	{
		if (i >= size)
		{
			newSize = i;
			break;
		}
	}
		
	int* newArray = createArray(newSize);
	int* bufArray = createArray(newSize);

	for (int i = 0; i < newSize; i++)
	{
		if (i < size) newArray[i] = array[i];
		else newArray[i] = maxInArray(array, size);
	}

	while (element <= newSize)
	{
		for (int i = 0; i < newSize; i++)
			if (i % element == 0)
			{
				int x1 = i, x2 = x1 + element / 2;
				for (int x = i; x < i + element; x++)
				{
					if (newArray[x1] > newArray[x2] && x2 < i + element && x2 < newSize) bufArray[x] = newArray[x2++];
					else if (x1 < i + element / 2 && x1 < newSize) bufArray[x] = newArray[x1++];
					else bufArray[x] = newArray[x];
				}
			}
		for (int i = 0; i < newSize; i++) newArray[i] = bufArray[i];
		element *= 2;
	}
	for (int i = 0; i < size; i++) array[i] = newArray[i];
	free(newArray);
	free(bufArray);
}

int* quickSort(int* array, int start, int final)
{
	int rightElement = final - 1;
	for (int x1 = 0; x1 < final; x1++)//������ ������ �����
	{
		if (array[final - 1] <= array[x1])//���� �������� ������ ������ �������� �� ���� ���������������
		{
			if (x1 == final - 1 && start < final - 1) quickSort(array, start, final - 1);
			else if (rightElement != NULL)
			{
				for (int x2 = rightElement; x2 >= x1; x2--)//������ ������� �����
				{
					if (x1 == x2 && array[final - 1] != array[x2])//���� ��� ����� �� ����� ����� ������ ������� � ���� ��������� � ��������� �������� �������� ������ �� ��� �������
					{
						replaycment(array, x1, final - 1);
						quickSort(array, start, rightElement);
						quickSort(array, rightElement + 1, final);
						rightElement = NULL;
					}
					else if (array[final - 1] > array[x2])//���� ������� ������ ��� ������ ���� �� ������ ������� �������� ������� ����� � �����
					{
						replaycment(array, x1, x2);
						rightElement = x2;
						break;
					}
				}
			}
			else break;
		}
	}
}