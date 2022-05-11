#include "monty.h"
/**
 * pop - deletes the node at index of a linked list
 * @head: head of the linked list.
 * @lineCount: node to be deleted.
 */
void pop(stack_t **head, unsigned int lineCount)
{
	stack_t *aux = *head, *tmp;

	if (!head || !*head)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lineCount);
		exit(EXIT_FAILURE);
	}
	if (aux->next == NULL)
	{
		free(aux);
		*head = NULL;
		glob.pop = 1;
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
