#include "monty.h"

/**
 * print_error - Prints the program error
 * Return: void
 */
void print_error(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			data.current_line, data.opcode);
	free_stack();
	fclose(data.file);
	exit(EXIT_FAILURE);
}

/**
 * _print_opcode_error - Print error related to an opcode
 * @line: The execution line
 * @msg: The error message
 * Return: void
 */
void _print_opcode_error(unsigned int line, char *msg)
{
	fprintf(stderr, "L%d: %s\n", line, msg);
	free_stack();
	fclose(data.file);
	exit(EXIT_FAILURE);
}
