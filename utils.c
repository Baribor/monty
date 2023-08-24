#include "monty.h"

/**
 * is_int - Checks if a character is a digit.
 *
 * @str: The character to check.
 * Return: 1 if true else 0
 */
int is_int(char *str)
{
	int i;

	for (i = 0; str[i]; ++i)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}

/**
 * execute_opcode - Executes the opcode
 * Return: void
 */
void execute_opcode(void)
{
	instruction_t execs[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop", opcode_pop},
		{"swap", opcode_swap},
		{"add", opcode_add},
		{"sub", opcode_sub},
		{"div", opcode_div},
		{"mul", opcode_mul},
		{"mod", opcode_mod},
		{"pchar", opcode_pchar},
		{"pstr", opcode_pstr},
		{"rotl", opcode_rotl},
		{NULL, NULL}};
	int i;

	data.opcode = strtok(data.line, " \n\t");
	if (!data.opcode)
		return;
	data.arg = strtok(NULL, " \n\t");

	for (i = 0; execs[i].opcode; ++i)
	{
		if (strcmp(execs[i].opcode, data.opcode) == 0)
		{
			execs[i].f(&data.stack, data.current_line);
			return;
		}
	}

	if (strcmp(data.opcode, "\n"))
		print_error();
}
