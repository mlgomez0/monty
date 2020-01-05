#include "monty.h"
/**
 *fun_add - adds the top two elements in a doubly linked list
 *@stack: doble pointer to the doubly linked list
 *@line_number:number to be pushed in the node
 */
void fun_add(stack_t **stack, unsigned int line_number)
{
	int temp_int;
	stack_t *temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp_int = (*stack)->n + (*stack)->next->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
		temp = NULL;
		(*stack)->n = temp_int;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all = 1;
	}
}
/**
 *fun_nop - This function does nothing
 *@stack: doble pointer to the doubly linked list
 *@line_number:number to be pushed in the node
 */
void fun_nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

