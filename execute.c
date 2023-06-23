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
	if (function == NULL || *function == '#')
		return;
	/* if opcode doesn't exist */
	fun_ptr = get_op_func(function);
	if (fun_ptr == NULL)
		command_error(stack, function, line_number, file);

	if (get_op_check(function, 1) && get_op_check(function, 2))
	{
		if (!get_op_check(function, 1)(stack, number, 0))
			command_error(stack, function, line_number, file);
		if (!get_op_check(function, 2)(stack, number, 0))
			command_error2(stack, function, line_number, file);
		fun_ptr(stack, line_number);
	}
	else if (get_op_check(function, 1))
	{
		if (get_op_check(function, 1)(stack, number, 0))
			fun_ptr(stack, line_number);
		else
			command_error(stack, function, line_number, file);
	}
	else
		fun_ptr(stack, line_number);

}

/**
 * get_op_check - Selects the correct function to perform
 * the right check for each opcode asked by the user
 * @op_name: the opcode
 * @check_num: the number of the check to be returned
 *
 * Return: A pointer to the function that corresponds to the
 * opcode and check_num given as a parameter
 */
int (*get_op_check(char *op_name, int check_num))(stack_t **, char *, int)
{
	conditions_t ops[] = {
		{"push", isValidNum, NULL},
		{"pint", isNotEmpty_st, NULL},
		{"pop", isNotEmpty_st, NULL},
		{"swap", notShort_st, NULL},
		{"add", notShort_st, NULL},
		{"sub", notShort_st, NULL},
		{"mul", notShort_st, NULL},
		{"div", notShort_st, div_by0},
		{NULL, NULL, NULL}
	};
	int i = 0;

	while (ops[i].fun_name != NULL && (strcmp(ops[i].fun_name, op_name) != 0))
		i++;
	if (check_num == 1)
		return (ops[i].check1);
	else
		return (ops[i].check2);
}
