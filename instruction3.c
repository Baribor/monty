#include "monty.h"

/**
 * opcode_pchar - Performs the pchar operation
 * @stack: The program stack
 * @line_number: Current execution line
 * Return: void
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = get_tail(stack);

	if (!top)
		_print_opcode_error(line_number, "can't pchar, stack empty");

	if (top->n < 0 || top->n > 127)
		_print_opcode_error(line_number, "can't pchar, value out of range");

	printf("%c\n", top->n);
}

/**
 * opcode_pstr - Performs the pstr operation
 * @stack: The program stack
 * @line: Current execution line
 * Return: void
 */
void opcode_pstr(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	stack_t *top = get_tail(stack);

	if (top)
	{
		while (top)
		{
			if (top->n <= 0 || top->n > 127)
				break;
			printf("%c", top->n);
			top = top->prev;
		}
	}

	printf("\n");
}

/**
 * opcode_rotl - Performs the rotl operation
 * @stack: The program stack
 * @line: Current execution line
 * Return: void
 */
void opcode_rotl(stack_t **stack, __attribute__((unused)) unsigned int line)
{
	stack_t *tail = get_tail(stack);

	if (!tail || !tail->prev)
		return;

	tail->prev->next = NULL;
	tail->next = *stack;
	tail->prev = NULL;
	(*stack)->prev = tail;
	*stack = tail;
}
