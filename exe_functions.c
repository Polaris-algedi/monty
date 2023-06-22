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
 * isValidNum - checks if a string representation of a number can be
 * converted into an int
 * @stack: double pointer to the first node
 * @number: string representation of a number
 * @num: integer
 *
 * Return: the check's result
 */
int isValidNum(__attribute__((unused)) stack_t **stack,
		char *number, __attribute__((unused)) int num)
{
	if (number != NULL && (atoi(number) != 0 || *number == '0'))
	{
		n = atoi(number);
		return (1);
	}
	return (0);
}