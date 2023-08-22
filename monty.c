#include "monty.h"

int main(int argc, char const *argv[])
{
	iptr_data data;
	init_data(&data);

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	begin_interpret(&data);
	return (EXIT_SUCCESS);
}
