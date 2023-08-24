#include "monty.h"

/**
 * opcode_push - Performs the push operation
 * @stack: The program stack
 * @line_number: Current execution line
 * Return: void
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *new_node;

	if (!data.arg || !is_int(data.arg))
		_print_opcode_error(line_number, "usage: push integer");

	tail = get_tail(stack);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack();
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(data.arg);
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!tail)
		*stack = new_node;
	else
	{
		new_node->prev = tail;
		tail->next = new_node;
	}
}

/**
 * opcode_pall - Performs the pall operation
 * @stack: The program stack
 * @line: Current execution line
 * Return: void
 */
void opcode_pall(stack_t **stack, unsigned int line __attribute__((unused)))
{
	stack_t *tail = get_tail(stack);

	while (tail)
	{
		printf("%d\n", tail->n);
		tail = tail->prev;
	}
}

/**
 * opcode_pint - Performs the pint operation
 * @stack: The program stack
 * @line_number: Current execution line
 * Return: void
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = get_tail(stack);

	if (!tail)
		_print_opcode_error(line_number, "can't pint, stack empty");

	printf("%d\n", tail->n);
}

/**
 * opcode_pop - Performs the pop operation
 * @stack: The program stack
 * @line_number: Current execution line
 * Return: void
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;

	tail = get_tail(stack);

	if (!tail)
		_print_opcode_error(line_number, "can't pop an empty stack");

	if (!tail->prev)
		*stack = NULL;
	else
		tail->prev->next = NULL;
	free(tail);
}

/**
 * opcode_swap - Performs the swap operation
 * @stack: The program stack
 * @line_number: Current execution line
 * Return: void
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = get_tail(stack), *temp;

	if (!tail || !tail->prev)
		_print_opcode_error(line_number, "can't swap, stack too short");

	temp = tail->prev->prev;

	tail->prev->next = NULL;
	tail->prev->prev = tail;
	tail->next = tail->prev;
	tail->prev = temp;
	if (!temp)
		*stack = tail;
}
