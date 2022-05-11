#include "monty.h"

void pchar(stack_t **head, unsigned int lineCount)
{
	stack_t *aux = *head;

	if (!*head)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", lineCount);
		head = NULL;
		return;
	}
	while (aux->next)
		aux = aux->next;
	if (aux->n < 0 || aux->n > 255)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", lineCount);
		head = NULL;
		return;
	}
	putchar(aux->n);
	putchar(10);
}
