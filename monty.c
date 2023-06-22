#include "monty.h"
int n = 15;


/**
 * monty - interpreter for Monty ByteCodes files
 * @filename: name of the Monty ByteCodes file
 */
void monty(char *filename)
{
	FILE *file = NULL;
	char buff[MAX_LEN];
	unsigned int line = 0;
	stack_t *head = NULL;
	/* open file */
	file = fopen(filename, "r");
	if (file == NULL)
		file_error(1, filename);

	/* loop & read & get command*/
	while (fgets(buff, MAX_LEN, file) != NULL)
	{
		/* execute it */
		line++;
		execute(&head, line, buff, file);
	}

	free_stack(head);

	/* close, do I have to check it too??? */
	fclose(file);
}

/**
 * get_op_func - Selects the correct function to perform
 * the opcode asked by the user
 * @op_name: the opcode
 *
 * Return: A pointer to the function that corresponds to the
 * opcode given as a parameter
 */
void (*get_op_func(char *op_name))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL && (strcmp(ops[i].opcode, op_name) != 0))
		i++;
	return (ops[i].f);
}


/**
* main - Entry point
* @argc: holds the number of command-line arguments passed to the program
* @argv: stores the command-line arguments passed to the program
*
* Return: Always 0 (Success)
*/
int main(int argc, char **argv)
{
	if (argc != 2)
		file_error(0, argv[0]);
	monty(argv[1]);
	return (0);
}
