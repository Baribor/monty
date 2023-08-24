#ifndef _MONTY_H
#define _MONTY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct interpreter_data - Interpreter data
 * @current_line: Current execution line
 * @file_name: The executing file name
 * @line: The current line in execution
 * @opcode: Opcode of the current command
 * @arg: Opcode arg
 * @stack: Head of the stack
 * @file: The file read from
 */
typedef struct interpreter_data
{
	unsigned int current_line;
	char *file_name;
	char *line;
	char *opcode;
	char *arg;
	stack_t *stack;
	FILE *file;
} iptr_data;

extern iptr_data data;

/* Util functions */
char *_strdup(char *str);
void reverse_string(char *str);
void number_to_string(char *buf, int num);
void _print_opcode_error(unsigned int line, char *msg);
int is_int(char *str);

/* Exec functions */
void begin_interpret(void);
void execute_opcode(void);
stack_t *get_tail(stack_t **stack);

void print_error(void);
void _print_err(char *str);
void free_stack(void);

/* Executors */
void opcode_push(stack_t **stack, unsigned int line_number);
void opcode_pall(stack_t **stack, __attribute__((unused)) unsigned int line);
void opcode_pint(stack_t **stack, unsigned int line_number);
void opcode_pop(stack_t **stack, unsigned int line_number);
void opcode_swap(stack_t **stack, unsigned int line_number);
void opcode_add(stack_t **stack, unsigned int line_number);
void opcode_sub(stack_t **stack, unsigned int line_number);
void opcode_div(stack_t **stack, unsigned int line_number);
void opcode_mul(stack_t **stack, unsigned int line_number);
void opcode_mod(stack_t **stack, unsigned int line_number);
void opcode_pchar(stack_t **stack, unsigned int line_number);
void opcode_pstr(stack_t **stack, __attribute__((unused)) unsigned int line);
void opcode_rotl(stack_t **stack, __attribute__((unused)) unsigned int line);

#endif
