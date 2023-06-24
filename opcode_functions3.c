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

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void pchar(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *top = *stack;

	printf("%c\n", top->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current && current->n > 0 && current->n < 128)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}


/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = NULL;
	int top_num = (*stack)->n;

	for (current = *stack; current->next; current = current->next)
		current->n = current->next->n;

	current->n = top_num;
}
