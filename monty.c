#include "monty.h"

iptr_data data = {0, NULL, NULL, NULL, NULL, NULL, NULL};

/**
 * main - The main program entry
 * @argc: The argument counter
 * @argv: The argument values
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argv;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	data.file_name = argv[1];
	begin_interpret();
	return (EXIT_SUCCESS);
}
