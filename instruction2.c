#include "monty.h"

/**
 * opcode_add - Performs the add operation
 * @stack: The program stack
 * @line_number: Current execution line
 * Return: void
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = get_tail(stack);

	if (!tail->prev)
		_print_opcode_error(line_number, "can't add, stack too short");

	tail->prev->n += tail->n;
	tail->prev->next = NULL;
	free(tail);
}

/**
 * opcode_sub - Performs the sub operation
 * @stack: The program stack
 * @line_number: Current execution line
 * Return: void
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = get_tail(stack);

	if (!tail->prev)
		_print_opcode_error(line_number, "can't sub, stack too short");

	tail->prev->n -= tail->n;
	tail->prev->next = NULL;
	free(tail);
}

/**
 * opcode_div - Performs the div operation
 * @stack: The program stack
 * @line_number: Current execution line
 * Return: void
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = get_tail(stack);

	if (!tail->prev)
		_print_opcode_error(line_number, "can't div, stack too short");

	if (tail->n == 0)
		_print_opcode_error(line_number, "division by zero");

	tail->prev->n /= tail->n;
	tail->prev->next = NULL;
	free(tail);
}

/**
 * opcode_mod - Performs the mod operation
 * @stack: The program stack
 * @line_number: Current execution line
 * Return: void
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = get_tail(stack);

	if (!tail->prev)
		_print_opcode_error(line_number, "can't mod, stack too short");

	if (tail->n == 0)
		_print_opcode_error(line_number, "division by zero");

	tail->prev->n %= tail->n;
	tail->prev->next = NULL;
	free(tail);
}

/**
 * opcode_mul - Performs the mul operation
 * @stack: The program stack
 * @line_number: Current execution line
 * Return: void
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = get_tail(stack);

	if (!tail->prev)
		_print_opcode_error(line_number, "can't mul, stack too short");

	tail->prev->n *= tail->n;
	tail->prev->next = NULL;
	free(tail);
}
