#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new = NULL, *next = NULL;

	if (!stack)
		exit(EXIT_FAILURE);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/* set the new structure to point to the next one */
	new->next = *stack;
	new->prev = NULL;
	new->n = n;
	/* set the next structure to point to the previous one */
	next = new->next;
	if (next)
		next->prev = new;
	/* set the header pointer */
	*stack = new;
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *top = *stack;

	printf("%d\n", top->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void pop(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *ptr_holder;

	ptr_holder = (*stack)->next;
	free(*stack);
	*stack = ptr_holder;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void swap(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *first, *second, *third;

	first = *stack;
	second = first->next;
	third = second->next;

	if (third)
		third->prev = first;

	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = NULL;

	*stack = second;
}

