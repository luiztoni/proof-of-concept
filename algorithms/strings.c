#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv)
{
	const int MAX_SIZE = 400;
	char str1[MAX_SIZE], str2[MAX_SIZE], ch, *p = NULL;
	int size = 0, i;

	printf("Enter str1: ");
	fgets(str1, MAX_SIZE, stdin);

	printf("Enter str2: ");
	fgets(str2, MAX_SIZE, stdin);

	size =  strcmp(str1, str2);
	if (!size)
	{
		printf("str1 = str2.\n");
	}
	else
	{
		printf("str1 != str2.\n");
	}


	printf("Type a character for search in str1: ");
	ch = getchar();
	p = strchr(str1, ch);
	if (!p)
		printf("Not found.\n");
	else
		printf(" '%c' in address %p\n", *p, p);

	size = strlen(str1);
	printf(" str1 size: %d\n", size);
	str1[size - 1] = ' ';

	size = strlen(str2);
	printf(" str2 size: %d\n", size);

	printf("str1 = str1 + str2 :\n");
	strcat(str1, str2);
	printf("new str1: %s\n", str1);

	size = strlen(str1);
	printf("str1 size: %d\n", size);

	printf("Copy str1 for str2...\n");
	strcpy(str2, str1);
	printf("new str2: %s\n", str2);
	
	i = 0;
	while (i < size)
	{
		str1[i] = tolower(str1[i]);
		str2[i] = toupper(str2[i]);
		i++;
	}
	
	printf(" uppercase str2: %s\n", str2);
	printf(" lowercase str1: %s\n", str1);
	return 0;
}
