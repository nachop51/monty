#include "monty.h"
/**
 *
 *
 */
void pstr(stack_t **head, unsigned int lineCount)
{
	stack_t *aux = *head;
	(void) lineCount;

	if (!*head)
	{
		putchar(10);
		return;
	}
	while (aux->next)
	{
		if (aux->n <= 0 || aux->n > 255)
			break;
		printf("AUX:N %d\n", aux->n);
		putchar(aux->n);
		aux = aux->next;
	}
	putchar(10);
}
