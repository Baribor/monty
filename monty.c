#include "monty.h"

/**
 * main - The main program entry
 * @argc: The argument counter
 * @argv: The argument values
 * Return: Always 0
 */
int main(int argc, char const *argv[])
{
	(void)argv;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
