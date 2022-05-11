#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @head: linked list.
 * @lineCount: line counter.
 */
void swap(stack_t **head, unsigned int lineCount)
{
	stack_t *list = *head;
	int aux_n;

	if (*head == NULL || list->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", lineCount);
		exit(EXIT_FAILURE);
	}
	while (list->next != NULL)
		list = list->next;
	aux_n = list->n;
	list->n = list->prev->n;
	list->prev->n = aux_n;
}
