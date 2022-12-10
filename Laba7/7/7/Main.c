#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include "lib.h"

void *prog1(void);
void *prog2(void);


int main()
{
	void (*funk) (void);
	printf("|+++++++++++|\n|1:  prog1  |\n|2:  prog2  |\n|3:  break  |\n|+++++++++++|\nYour choice: ");
	switch (inputRestrictedInteger(1, 3))
	{
		case 1:
			funk = prog1;
			funk();
			main();
			break;
		case 2:
			funk = prog2;
			funk();
			main();
			break;
		case 3:
			break;
	}
	
	return 0;
}

void *prog1(void)
{
	printf("Input str: \n");
	char* str = (char*)calloc(256, 1);
	inputString(str);
	str = deleteP(str);
	printf("%s", str);
	free(str);
}

void *prog2(void)
{
	char* S = calloc(256, 1);
	char* S0 = calloc(256, 1);
	printf("Input S: \n");
	inputString(S);
	printf("Input S0: \n");
	inputString(S0);
	printf("Input a: ");
	int a = inputMorePositiveInteger();
	printf("Input b: ");
	int b = inputMorePositiveInteger();
	pasteFromS1InS2(S, S0, a, b);
	printf("New S0: \n%s", S0);
	printf("\n");
}