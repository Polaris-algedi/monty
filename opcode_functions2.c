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
void nop(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	return;
}
