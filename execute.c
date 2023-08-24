#include "monty.h"

/**
 * begin_interpret - Starts program interpretation
 * Return: void
 */
void begin_interpret(void)
{
	char buf[1024];

	data.file = fopen(data.file_name, "r");
	if (!data.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", data.file_name);
		exit(EXIT_FAILURE);
	}

	while (fgets(buf, sizeof(buf), data.file))
	{
		data.current_line++;
		data.line = buf;
		/* execute_opcode(); */
	}
	fclose(data.file);
	/* free_stack(); */
}
