#include "monty.h"

/**
 * execute - executes the opcode based on
 * the provided operation name in the bytecode file
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 * @command: the instruction
 * @file: the bytecode file pointer
 *
 */
void execute(stack_t **stack, unsigned int line_number,
		char *command, FILE *file)
{
	char *delimiter = " \t\n";
	char *function = strtok(command, delimiter);
	char *number = strtok(NULL, delimiter);
	void (*fun_ptr)(stack_t **, unsigned int);
	/* if there empty line */
	if (function == NULL)
		return;
	/* if opcode doesn't exist */
	fun_ptr = get_op_func(function);
	if (fun_ptr == NULL)
		command_error(stack, function, line_number, file);

	if (strcmp(function, "push") == 0)
	{
		if (number != NULL && (atoi(number) != 0 || *number == '0'))
		{
			n = atoi(number);
			fun_ptr(stack, line_number);
		}
		else
			command_error(stack, function, line_number, file);
	}
	else if (strcmp(function, "pint") == 0 || strcmp(function, "pop") == 0)
	{
		if (*stack != NULL)
			fun_ptr(stack, line_number);
		else
			command_error(stack, function, line_number, file);
	}
	else if (strcmp(function, "swap") == 0 || strcmp(function, "add") == 0)
	{
		if (stack_len(*stack) > 1)
			fun_ptr(stack, line_number);
		else
			command_error(stack, function, line_number, file);
	}
	else
		fun_ptr(stack, line_number);

}

