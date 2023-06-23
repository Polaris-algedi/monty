#include "monty.h"

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void mod(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *first, *second;

	first = *stack;
	second = first->next;

	second->n = (second->n) % (first->n);
	second->prev = NULL;

	free(first);

	*stack = second;
}
