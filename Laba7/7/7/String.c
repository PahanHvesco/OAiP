#include <stdio.h>
#include <stdlib.h>

char* deleteP(char* str)
{
	char* output = calloc(256, 1);
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (j == 0 && str[i] == ' ') continue;
		output[j] = str[i];
		if (str[i] == ' ')
		{
			for (int i2 = i; str[i2] == ' '; i2++)
				i = i2;
			output[j] = str[i];
		}
		if (str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!' || str[i] == ':' || str[i] == ';')
		{
			if (str[i - 1] == ' ')
			{
				output[j - 1] = str[i];
				output[j] = ' ';
			}
			else if (str[i + 1] != ' ')
				output[++j] = ' ';
		}
		j++;
	}
	output[j++] = '\n';
	free(str);
	return output;
}

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

void printString(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
		printf("%s", str[i]);
	printf('\n');
}

void pasteFromS1InS2(char* S, char* S0, int a, int b)
{
	for (int i = a, j = 0; i < a + b; i++, j++)
	{
		if (i > lengthStr(S0)) realloc(S0, lengthStr(S0) + 1);
		S0[i] = S[j];
	}
}

int lengthStr(char* str)
{
	int i = 0;
	for (; str[i] != '\0'; i++);
	return i;
}