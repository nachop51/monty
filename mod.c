#include "monty.h"

/**
 * mod - Computes the rest of the division of the second last by the top.
 * @head: Linked list.
 * @lineCount: Number of the line.
 */
void mod(stack_t **head, unsigned int lineCount)
{
	stack_t *list = *head;
	int result = 0;

	if (*head == NULL || list->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", lineCount);
		head = NULL;
		return;
	}
	while (list->next->next != NULL)
		list = list->next;
	if (list->next->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineCount);
		head = NULL;
		return;
	}
	result = list->n % list->next->n;
	list->n = result;
	pop(head, lineCount);
}
