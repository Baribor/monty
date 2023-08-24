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
		{OPCODE_PUSH, opcode_push},
		{OPCODE_PALL, opcode_pall},
		{OPCODE_PINT, opcode_pint},
		{OPCODE_POP, opcode_pop},
		{OPCODE_SWAP, opcode_swap},
		{OPCODE_ADD, opcode_add},
		{OPCODE_SUB, opcode_sub},
		{OPCODE_DIV, opcode_div},
		{OPCODE_MUL, opcode_mul},
		{OPCODE_MOD, opcode_mod},
		{OPCODE_PCHAR, opcode_pchar},
		{OPCODE_PSTR, opcode_pstr},
		{OPCODE_ROTL, opcode_rotl},
		{OPCODE_ROTR, opcode_rotr},
		{OPCODE_NOP, opcode_nop},
		{NULL, NULL}};
	int i;

	data.opcode = strtok(data.line, " \n\t");
	if (!data.opcode || data.opcode[0] == '#')
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
