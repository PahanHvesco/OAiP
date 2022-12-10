#include <stdio.h>
#include <stdlib.h>

void inputString(char** str, int row)
{
	char c = ' ';
	int i = 0;
	for (int y = 0; y < row; y++)
	{
		for (;(c = getchar()) != '\n'; i++)
		{
			str[y][i] = c;
		}
		str[y][i] = '\0';
		i = 0;
	}
}

int lengthStr(char** str, int row)
{
	int i = 0;
	for (; str[row][i] != '\0'; i++);
	return i;
}

void freeStr(char** str, int row)
{

}

void sorted(char** str, int start, int finish)
{
	int leftFlag = start, rightFlag = finish;
	int reference = (start + finish) / 2;
	do
	{
		while (lengthStr(str, leftFlag) < lengthStr(str, reference)) leftFlag++;
		while (lengthStr(str, rightFlag) > lengthStr(str, reference)) rightFlag--;
		if (leftFlag <= rightFlag)
		{
			char* c = str[leftFlag];
			str[leftFlag] = str[rightFlag];
			str[rightFlag] = c;
			leftFlag++;
			rightFlag--;
		}
	} while(leftFlag <= rightFlag);
	if (leftFlag < finish)
	{
		sorted(str, leftFlag, finish);
	}
	if (rightFlag > start)
	{
		sorted(str, start, rightFlag);
	}
}