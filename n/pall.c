#include "monty.h"

/**
 * print_dlistint - Prints out the elements of a linked list
 * @h: Head of the linked list
 * Return: Length value
 */
void pall(stack_t **head, unsigned int line)
{
	stack_t *h = *head;

	line = line;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
