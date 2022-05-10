#include "monty.h"
/**
 *
 *
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int lineCount)
{
	stack_t *list = *head;
	int aux_n;

	if (*head == NULL || list->next == NULL)
		return;
	aux_n = list->n;
	list = add_node_end(head);
	list->n = aux_n;
	delete_first_node(head);
}
