#include"monty.h"

int free_all = 0;

/**
 *main - funtion that interprets Monty bitecode
 *@ac: # of main arguments
 *@av: command line arguments
 *Return: 0 on success and 1 on failure
 **/
int main(int ac, char **av)
{
	FILE *fd;
	size_t w_read;
	char *_buf = NULL, *no_command = "\n";
	unsigned int num_lines = 1;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&_buf, &w_read, fd) != EOF)
	{
		if (strcmp(_buf, no_command) != 0)
		{
			check_fun(_buf, num_lines, &stack);
			if (free_all == 1)
			{
				fclose(fd);
				free_dlistint(stack);
				free(_buf);
				exit(EXIT_FAILURE);
			}
		}
		num_lines++;
	}
	fclose(fd);
	free_dlistint(stack);
	free(_buf);
	return (0);
}
/**
 *check_fun - determines which function to use
 *@_line: Line read in the Monty file
 *@num_lines: Number of lines in file
 *@stack: pointer to a pointer for doubly linked list
 *Return: apointer to a stack_t valiable
 **/
stack_t *check_fun(char *_line, unsigned int num_lines, stack_t **stack)
{
	char *arg_line, *_opcode, *arg_sep = " \t\r\a\n", *_zero = "0";
	unsigned int m, i = 0;
	instruction_t arr_fun[] = {
		{"push", fun_push},
		{"pall", fun_pall},
		{"pint", fun_pint},
		{"pop", fun_pop}
	};

	arg_line = strtok(_line, arg_sep);
	_opcode = arg_line;
	for (i = 0; i < 4; i++)
	{
		if (strcmp(arr_fun[i].opcode, arg_line) == 0)
		{
			arg_line = strtok(NULL, arg_sep);
			if (arg_line)
				m = atoi(arg_line);
			if ((i == 0 && arg_line == NULL) || (arg_line && m == 0
				 && strcmp(arg_line, _zero) != 0 && i == 0))
			{
				{
					fprintf(stderr, "L%u: usage: push integer\n", num_lines);
					free_all = 1;
					return (*stack);
				}
			}
			else if (i != 0)
				m = num_lines;
			arr_fun[i].f(stack, m);
			return (*stack);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", num_lines, _opcode);
	free_all = 1;
	return (*stack);
}
/**
 *free_dlistint - free the stack once all lines are executed
 *@stack: pointer to the doubly linked list
 **/
void free_dlistint(stack_t *stack)
{
	stack_t *temp;
	stack_t *temp2;

	temp = stack;
	if (stack == NULL)
		return;
	while (temp->next)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	free(temp);
}
