#include "monty.h"

/**
 * pchar - Prints the last number of the stack in char
 * @head: Linked list.
 * @lineCount: Number of the line.
 */
void pchar(stack_t **head, unsigned int lineCount)
{
	stack_t *aux = *head;

	if (!*head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineCount);
		head = NULL;
		return;
	}
	while (aux->next)
		aux = aux->next;
	if (aux->n < 0 || aux->n > 255)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineCount);
		head = NULL;
		return;
	}
	putchar(aux->n);
	putchar(10);
}