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
/**
 *fun_pchar - prints the char at the top of the stack
 *@stack: doble pointer to the doubly linked list
 *@line_number:number to be pushed in the node
 */
void fun_pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
		{
			putchar((*stack)->n);
			putchar('\n');
		}
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
			free_all = 1;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_all = 1;
	}
}
/**
 *fun_pstr - prints the string starting at the top of the stack
 *@stack: doble pointer to the doubly linked list
 *@line_number:number to be pushed in the node
 */
void fun_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	temp = *stack;
	if (*stack != NULL)
	{
		while (temp && temp->n > 0 && temp->n <= 127)
		{
			putchar(temp->n);
			temp = temp->next;
		}
	}
	putchar('\n');
	line_number = line_number;
}
