#include "monty.h"

void push(stack_t **head, __attribute__((unused)) unsigned int line)
{
	add_node_end(head);
}

/**
 * add_node_end - Adds a new node at the end of a doubly linked list
 * @head: Head of the linked list
 * @n: Number
 *
 * Return: A pointer to the new node
 */
stack_t *add_node_end(stack_t **head)
{
	stack_t *new, *last;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = argument;
	new->next = NULL;
	if (!*head)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	last = *head;
	while (last->next)
		last = last->next;
	new->prev = last;
	last->next = new;
	return (new);
}
