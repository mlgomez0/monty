#include "monty.h"
/**
 *fun_mod - determines the module between tops in a doubly linked list
 *@stack: doble pointer to the doubly linked list
 *@line_number:number to be pushed in the node
 */
void fun_mod(stack_t **stack, unsigned int line_number)
{
	int temp_int;
	stack_t *temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		if ((*stack)->n != 0)
		{
			temp_int = ((*stack)->next->n) % ((*stack)->n);
			temp = *stack;
			*stack = (*stack)->next;
			(*stack)->prev = NULL;
			free(temp);
			temp = NULL;
			(*stack)->n = temp_int;
		}
		else
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			free_all = 1;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_all = 1;
	}
}
