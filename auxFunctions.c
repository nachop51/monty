#include "monty.h"

int _isdigit(char *checkArg)
{
	if (checkArg[0] == '-')
	{
		if (checkArg[1] >= 48 && checkArg[1] <= 57)
		{
			return (1);
		}
		return (0);
	}
	else if (checkArg[0] >= 48 && checkArg[0] <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void printErr(stack_t **head, FILE *fd, char *buffer, unsigned int lineCount)
{
	dprintf(2, "L%d: usage: push integer\n", lineCount);
	free_all(head, fd, buffer);
	exit(EXIT_FAILURE);
}

int checkFunc(char *command)
{
	if (strcmp(command, "push") == 0)
		return (1);
	if (strcmp(command, "nop") == 0)
		return (2);
	if (command[0] == '#')
		return (2);
	if (strcmp(command, "rotl") == 0)
		return (3);
	if (strcmp(command, "rotr") == 0)
		return (3);
	if (strcmp(command, "queue") == 0)
		return (3);
	if (strcmp(command, "stack") == 0)
		return (3);
	return (0);
}