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
