#include "monty.h"

void push(stack_t **head, unsigned int line)
{
	line = line;
	add_node_end(head);
}

/**
 * add_node_end - Adds a new node at the end of a doubly linked list
 * @head: Head of the linked list
 * @n: Number
 *
 * Return: A pointer to the new node
 */
stack_t *add_node_end(stack_t **head)
{
	stack_t *new, *last;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = argument;
	new->next = NULL;
	if (!*head)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	last = *head;
	while (last->next)
		last = last->next;
	new->prev = last;
	last->next = new;
	return (new);
}

/**
 *  add_dnodeint - adds a new node at the beginning of a linked list.
 *  @head: head of the node.
 *  @n: value to be added to the new node.
 *  Return: the address of the new element, or NULL if it failed
 */
stack_t *add_node_start(stack_t **head)
{
	stack_t *new_node, *first_node;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	else
	{
		first_node = *head;
		first_node->prev = new_node;
		new_node->next = first_node;
		*head = new_node;
		return (new_node);
	}
}

/**
 * pop - deletes the node at index of a linked list
 * @head: head of the linked list.
 * @lineCount: node to be deleted.
 */
void delete_first_node(stack_t **head)
{
	stack_t *current_node = *head;

	*head = current_node->next;
	if (current_node->next)
		current_node->next->prev = NULL;
	current_node->next = NULL;
	free(current_node);
}
