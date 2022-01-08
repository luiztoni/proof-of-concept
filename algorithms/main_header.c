#include <stdio.h>
#include "header.h"

int main(int argc, char** argv)
{
	long resp = fat(5);
	printf("5! = %ld\n", resp);
	return 0;
}