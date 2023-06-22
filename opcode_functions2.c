#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void add(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *first, *second;

	first = *stack;
	second = first->next;

	second->n += first->n;
	second->prev = NULL;

	free(first);

	*stack = second;
}

/**
 * nop - doesn’t do anything
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
}

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void sub(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *first, *second;

	first = *stack;
	second = first->next;

	second->n -= first->n;
	second->prev = NULL;

	free(first);

	*stack = second;
}

/**
 * mul - multiplies the second top element of
 * the stack with the top element of the stack
 * the second top element of the stack
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void mul(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *first, *second;

	first = *stack;
	second = first->next;

	second->n = (second->n) * (first->n);
	second->prev = NULL;

	free(first);

	*stack = second;
}
