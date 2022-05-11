#include "monty.h"

/**
 * free_list - Frees a doubly linked list.
 * @head: Linked list.
 */
void free_list(stack_t *head)
{
	stack_t *aux;

	while (head)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
}

void closeFile(FILE *fd)
{
	int i = 0;

	i = fclose(fd);
	if (i != 0)
	{
		fprintf(stderr, "Can't close file\n");
	}
}

void free_all(stack_t **head, FILE *fd, char *buffer)
{
	free_list(*head);
	closeFile(fd);
	free(buffer);
}