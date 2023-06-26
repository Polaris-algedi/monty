#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *stack2 = NULL, *current = *stack;
	int n1 = n;

	if (line_number == 0)
		add_node_top(stack, line_number);
	else
	{
		/* Queue implementation using stack */

		while (current)
		{
			n = current->n;
			add_node_top(&stack2, line_number);
			current = current->next;
			pop(stack, line_number);
		}
		n = n1;
		add_node_top(stack, line_number);
		current = stack2;
		while (current)
		{
			n = current->n;
			add_node_top(stack, line_number);
			current = current->next;
			pop(&stack2, line_number);
		}
	}
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
