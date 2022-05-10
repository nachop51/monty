#include "monty.h"
/**
 *
 */
void pint(stack_t **head, unsigned int lineCount)
{
	stack_t *list;

	if (*head == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", lineCount);
		exit(EXIT_FAILURE);
	}
	list = *head;
	while (list->next != NULL)
		list = list->next;
	printf("%d\n", list->n);
}
