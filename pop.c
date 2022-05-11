#include "monty.h"
/**
 * pop - deletes the node at index of a linked list
 * @head: head of the linked list.
 * @lineCount: node to be deleted.
 */
void pop(stack_t **head, unsigned int lineCount)
{
	stack_t *aux = *head, *tmp;

	if (!*head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineCount);
		exit(EXIT_FAILURE);
	}
	if (aux->next == NULL)
	{
		(*head)->next = NULL;
		(*head)->prev = NULL;
		*head = NULL;
		free(aux);
	}
	else
	{
		while (aux->next->next)
			aux = aux->next;
		tmp = aux->next;
		aux->next = NULL;
		free(tmp);
	}
}
