#include "monty.h"


/**
 * free_stack - frees a doubly linked list
 * @head: points to the first node
 */
void free_stack(stack_t *head)
{
	stack_t *ptr_holder;

	while (head)
	{
		ptr_holder = head->next;
		free(head);
		head = ptr_holder;
	}
}



/**
 * stack_len - counts the number of elements in a linked stack_t list
 * @h: points to the first noide
 *
 * Return: The number of elements
 */
size_t stack_len(const stack_t *h)
{
	size_t count_node;

	for (count_node = 0; h; count_node++)
		h = h->next;

	return (count_node);
}

/**
 * add_node_top - add an element to the top of the stack
 * @stack: double pointer to the first node
 * @line_number: the line number in the file
 */
void add_node_top(stack_t **stack, UNUSED unsigned int line_number)
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
	/* set the new node to point to the next one */
	new->next = *stack;
	new->prev = NULL;
	new->n = n;
	/* set the next node to point to the previous one */
	next = new->next;
	if (next)
		next->prev = new;
	/* set the header pointer */
	*stack = new;
}
