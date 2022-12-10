#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include "lib.h"

int main(int argc, char** argv)
{	
	sorted(argv, 1, argc-1);
	printf("\n");
	for (int i = 1; i < argc-1; i++)
		printf("%s\n", argv[i]);
	return 0;
}