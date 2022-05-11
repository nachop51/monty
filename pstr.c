#include "monty.h"
/**
 * pstr - Prints all the integers like a char.
 * @head: Linked list.
 * @lineCount: Number of the line.
 */
void pstr(stack_t **head, unsigned int lineCount)
{
	stack_t *aux = *head;
	(void)lineCount;

	if (!head || !*head)
	{
		putchar(10);
		return;
	}
	while (aux->next)
		aux = aux->next;
	while (aux)
	{
		if (aux->n <= 0 || aux->n > 127)
			break;
		putchar(aux->n);
		aux = aux->prev;
	}
	putchar(10);
}
