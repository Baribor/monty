#include "monty.h"

/**
 * get_tail - Gets the tail of the stack
 * @stack: The execution stack
 * Return: The tail else NULL if no node
 */
stack_t *get_tail(stack_t **stack)
{
	stack_t *current;

	if (!stack || !*stack)
		return (NULL);

	current = *stack;

	while (current->next)
		current = current->next;
	return (current);
}

/**
 * free_stack - Frees the stack
 * Return: void
 */
void free_stack(void)
{
	stack_t *current = data.stack, *temp;

	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
