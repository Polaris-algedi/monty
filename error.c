#include "monty.h"


/**
 * command_error - handles error conditions for specific
 * stack operations based on the provided op_name (operation name)
 * @stack: double pointer to the first node
 * @op_name: the opcode
 * @line_number: the line number in the file
 * @file: monty byte code file pointer
 */
void command_error(stack_t **stack, char *op_name,
		unsigned int line_number, FILE *file)
{
	ErrorInfo_t errors[] = {
		{"push", "usage: push integer"},
		{"pint", "can't pint, stack empty"},
		{"pop", "can't pop an empty stack"},
		{"swap", "can't swap, stack too short"},
		{"add", "can't add, stack too short"},
		{"sub", "can't sub, stack too short"},
		{"mul", "can't mul, stack too short"},
		{"div", "can't div, stack too short"},
		{"mod", "can't mod, stack too short"},
		{"pchar", "can't pchar, stack empty"},
		{NULL, NULL}
	};
	int i = 0;

	while (errors[i].fun_name != NULL &&
			(strcmp(errors[i].fun_name, op_name) != 0))
		i++;

	if (errors[i].fun_name != NULL)
		fprintf(stderr, "L%u: %s\n", line_number, errors[i].error_message);
	else
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op_name);

	free_stack(*stack);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * command_error - handles error conditions for specific
 * stack operations based on the provided op_name (operation name)
 * @stack: double pointer to the first node
 * @op_name: the opcode
 * @line_number: the line number in the file
 * @file: monty byte code file pointer
 */
void command_error2(stack_t **stack, char *op_name,
		unsigned int line_number, FILE *file)
{
	ErrorInfo_t errors[] = {
		{"div", "division by zero"},
		{"mod", "division by zero"},
		{"pchar", "can't pchar, value out of range"},
		{NULL, NULL}
	};
	int i = 0;

	while (errors[i].fun_name != NULL &&
			(strcmp(errors[i].fun_name, op_name) != 0))
		i++;

	if (errors[i].fun_name != NULL)
		fprintf(stderr, "L%u: %s\n", line_number, errors[i].error_message);
	else
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op_name);

	free_stack(*stack);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * file_error - handles different error cases based on
 * the provided num (error number) and file (file name)
 * @num: error number.
 * @file: file name.
 */

void file_error(int num, char *file)
{
	switch (num)
	{
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
			break;
		case 1:
			fprintf(stderr, "Error: Can't open file %s\n", file);
			exit(EXIT_FAILURE);
			break;
		case 2:
			fprintf(stderr, "Error: Can't read file: %s\n", file);
			exit(EXIT_FAILURE);
			break;
		case 3:
			fprintf(stderr, "Error: Can't close file: %s\n", file);
			exit(EXIT_FAILURE);
			break;
		default:
			fprintf(stderr, "Error: Unvalid file format: %s\n", file);
			exit(EXIT_FAILURE);
			break;
	}
}
