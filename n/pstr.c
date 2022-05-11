#include "monty.h"
/**
 *
 *
 */
void pstr(stack_t **head, unsigned int lineCount)
{
	stack_t *aux = *head;
	(void)lineCount;

	if (!*head)
	{
		putchar(10);
		return;
	}
	while (aux->next)
		aux = aux->next;
	while (aux->prev)
	{
		if (aux->n <= 0 || aux->n > 255)
			break;
		putchar(aux->n);
		aux = aux->prev;
	}
	putchar(10);
}
