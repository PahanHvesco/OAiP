#include <stdio.h>
#include <stdlib.h>

void inputString(char* str)
{
	char c = ' ';
	int i = 0;
	for (;(c = getchar()) != '\n'; i++)
	{
		str[i] = c;
	}
	str[i] = '\0';
}

int isItNumber(char c)
{
	if (c >= '0' && c <= '9') return 1;
	else return 0;
}

int sumIntInString(char* str)
{
	int sum = 0;
	for (int i = 0; str[i] != '\0'; i++)
		if (isItNumber(str[i]) )
		{
			int number = 0;
			for (int j = i; ; j++)
			{
				if (isItNumber(str[j]) && str[j]!='\0')number = (j-i)>0?number * 10 + (str[j] - '0'):number + (str[j] - '0');
				else
				{
					sum += number;
					i = j-1;
					break;
				}
			}
		}
	return sum;
}