#include "monty.h"

/**
 * isNotEmpty_st - checks if it's not an empty stack
 * @stack: double pointer to the first node
 * @number: string representation of a number
 * @num: integer
 *
 * Return: the check's result
 */
int isNotEmpty_st(stack_t **stack, __attribute__((unused))
		char *number, __attribute__((unused)) int num)
{
	return (*stack != NULL);
}

/**
 * notShort_st - checks if it's not a short stack
 * @stack: double pointer to the first node
 * @number: string representation of a number
 * @num: integer
 *
 * Return: the check's result
 */
int notShort_st(stack_t **stack, __attribute__((unused))
		char *number, __attribute__((unused)) int num)
{
	return (stack_len(*stack) > 1);
}

/**
 * isNumber - checks if a string representation of a number can be
 * converted into an int
 * @stack: double pointer to the first node
 * @number: string representation of a number
 * @num: integer
 *
 * Return: the check's result
 */
int isNumber(UNUSED stack_t **stack, char *number, UNUSED int num)
{
	char *start = number;
	/* Handle empty string */
	if (number == NULL || *number == '\0')
		return (0);

	/* Handle optional sign (+ or -) */
	if (*number == '+' || *number == '-')
		number++;

	/* Check remaining characters */
	while (*number != '\0')
	{
		if (*number < '0' || *number > '9')
			return (0);

		number++;
	}
	n = atoi(start);
	return (1);
}

/**
 * div_by0 - checks if the top element of the stack isn't 0
 * @stack: double pointer to the first node
 * @number: string representation of a number
 * @num: integer
 *
 * Return: the check's result
 */
int div_by0(stack_t **stack, UNUSED char *number, UNUSED int num)
{
	return ((*stack)->n != 0);
}

/**
 * isInAscii - checks if the value is not in the ascii table
 * @stack: double pointer to the first node
 * @number: string representation of a number
 * @num: integer
 *
 * Return: the check's result
 */
int isInAscii(stack_t **stack, UNUSED char *number, UNUSED int num)
{
	stack_t *top = *stack;

	return (top->n >= 0 && top->n <= 127);
}
