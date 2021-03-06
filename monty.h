#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int free_all;
stack_t *check_fun(char *_line, unsigned int num_lines, stack_t **stack);
void fun_push(stack_t **stack, unsigned int line_number);
void fun_pall(stack_t **stack, unsigned int line_number);
void fun_pint(stack_t **stack, unsigned int line_number);
void fun_pop(stack_t **stack, unsigned int line_number);
void free_dlistint(stack_t *stack);
void fun_swap(stack_t **stack, unsigned int line_number);
void fun_add(stack_t **stack, unsigned int line_number);
void fun_nop(stack_t **stack, unsigned int line_number);
void fun_sub(stack_t **stack, unsigned int line_number);
void fun_div(stack_t **stack, unsigned int line_number);
void (*fun_select(char *a_l, int i, int *k))(stack_t **s, unsigned int l_n);
void fun_mul(stack_t **stack, unsigned int line_number);
void fun_mod(stack_t **stack, unsigned int line_number);
void fun_pchar(stack_t **stack, unsigned int line_number);
void fun_pstr(stack_t **stack, unsigned int line_number);
void fun_rotl(stack_t **stack, unsigned int line_number);
void fun_rotr(stack_t **stack, unsigned int line_number);
void fun_stack(stack_t **stack, unsigned int line_number);
void fun_queue(stack_t **stack, unsigned int line_number);
int check_alpha(char *s);

#endif
