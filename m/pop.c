#include "monty.h"
/**
 * pop - deletes the node at index of a linked list
 * @head: head of the linked list.
 * @lineCount: node to be deleted.
 * Return: 1 on success, -1 on failure.
 */
void pop(stack_t **head, unsigned int lineCount)
{
	stack_t *current_node = *head, *cpy = *head;
	unsigned int index = 0, i = 0;

	if (*head == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack>", lineCount);
		exit(EXIT_FAILURE);
	}
	while (cpy->next != NULL)
	{
		index++;
		cpy = cpy->next;
	}
	if (index == 0)
	{
		*head = current_node->next;
		if (current_node->next)
			current_node->next->prev = NULL;
		current_node->next = NULL;
		free(current_node);
	}
	while (i < index)
	{
		current_node = current_node->next;
		i++;
	}
	current_node->prev->next = current_node->next;
	if (current_node->next != NULL)
		current_node->next->prev = current_node->prev;
	free(current_node);
}
