#include "monty.h"
/**
 *fun_push - creates a node in a doubly linked list
 *@stack: doble pointer to the doubly linked list
 *@line_number:number to be pushed in the node
 */
void fun_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;

	if (stack != NULL)
	{
		newnode = malloc(sizeof(stack_t));
		if (newnode == NULL)
		{
			fprintf(stderr,"Error: malloc failed\n");
			free_all = 1;
		}
		else
		{
			newnode->n = line_number;
			newnode->next = NULL;
			newnode->prev = NULL;
		}
	}
	if (*stack == NULL)
		*stack = newnode;
	else
	{
		(*stack)->prev = newnode;
		newnode->next = *stack;
		*stack = newnode;
	}

}
/**
 *fun_pall - prints a doubly linked list
 *@stack: doble pointer to the doubly linked list
 *@line_number: number of the current line read in .m file
 */
void fun_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	h = *stack;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	line_number = line_number;
}
/**
 *fun_pint - prints first element in a doubly linked list
 *@stack: doble pointer to the doubly linked list
 *@line_number: number of the current line read in .m file
 */

void fun_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all = 1;
	}
	else
		printf("%d\n", (*stack)->n);
}
/**
 *fun_pop - removes the first node in a doubly linked list
 *@stack: double pointer to the doubly linked list
 *@line_number: number of the current line read in .m file
 */
void fun_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all = 1;
	}
	else if ((*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
		temp = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
