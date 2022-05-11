#include "monty.h"
/**
 * _div - divides the second top element of the stack by the top element.
 * @head: Linked list.
 * @lineCount: Number of the line.
 */
void _div(stack_t **head, unsigned int lineCount)
{
	stack_t *list = *head;
	int result = 0;

	if (*head == NULL || list->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", lineCount);
		head = NULL;
		return;
	}
	while (list->next->next != NULL)
		list = list->next;
	if (list->next->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", lineCount);
		head = NULL;
		return;
	}
	result = list->n / list->next->n;
	list->n = result;
	pop(head, lineCount);
}
