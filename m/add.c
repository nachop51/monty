#include "monty.h"
/**
 *
 */
void add(stack_t **head, unsigned int lineCount)
{
	stack_t *list = *head;
	int result = 0;

	if (*head == NULL || list->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", lineCount);
		exit(EXIT_FAILURE);
	}
	while (list->next->next != NULL)
		list = list->next;
	result = list->n + list->next->n;
	list->n = result;
	pop(head, lineCount);
}
