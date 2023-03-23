#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * main - main program
 * @ac: number of arguments passed to main
 * @argv: array of arguments
 *
 * Return: 0 if successful
 */

int main(int ac, char **argv)
{
	FILE *ptr;
	char ch;
	char str_[50];

	/* Check argument to monty */
	if (ac != 2) /* No file or more than 1 file */
	{
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open file containing monty bytecodes and handle errors */
	ptr = fopen(argv[1], "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stderr, "%s successfully opened\n", argv[1]);

	/* Read contents of file */
	/*do {
		ch = fgetc(ptr);
		printf("%c", ch);
	} while (ch != EOF); */
	while (!feof(ptr))
	{
		ch = fgetc(ptr);
		printf("%c", ch);
	}
	ptr = fopen(argv[1], "r");
	while (fgets(str_, 50, ptr))
		printf("%s", str_);


	fclose(ptr);
	return (0);
}
