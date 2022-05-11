#include "monty.h"

/**
 * pall - Prints out the elements of a linked list
 * @head: Head of the linked list
 * @line: Number of the line.
 * Return: Length value
 */
void pall(stack_t **head, unsigned int line)
{
	stack_t *h = *head;

	if (*head == NULL)
		return;
	line = line;
	while (h->next)
		h = h->next;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->prev;
	}
}
