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
/**
 *fun_sub - substracts the first elements from second in a doubly linked list
 *@stack: doble pointer to the doubly linked list
 *@line_number:number to be pushed in the node
 */
void fun_sub(stack_t **stack, unsigned int line_number)
{
	int temp_int;
	stack_t *temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp_int = (*stack)->next->n - (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
		temp = NULL;
		(*stack)->n = temp_int;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_all = 1;
	}
}
/**
 *fun_div - divides the second element by the top in a doubly linked list
 *@stack: doble pointer to the doubly linked list
 *@line_number:number to be pushed in the node
 */
void fun_div(stack_t **stack, unsigned int line_number)
{
	int temp_int;
	stack_t *temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		if ((*stack)->n != 0)
		{
			temp_int = ((*stack)->next->n) / ((*stack)->n);
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
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_all = 1;
	}
}
/**
 *fun_mul - multiplies the top two elements of a doubly linked list
 *@stack: doble pointer to the doubly linked list
 *@line_number:number to be pushed in the node
 */
void fun_mul(stack_t **stack, unsigned int line_number)
{
	int temp_int;
	stack_t *temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp_int = ((*stack)->n) * ((*stack)->next->n);
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
		temp = NULL;
		(*stack)->n = temp_int;
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_all = 1;
	}
}
