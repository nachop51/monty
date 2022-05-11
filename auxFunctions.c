#include "monty.h"

/**
 * _isdigit - Checks if a given string is a digit or not.
 * @checkArg: String to check.
 * Return: 1 if is a digit, 0 if is not.
 */
int _isdigit(char *checkArg)
{
	int i = 0;

	if (checkArg[0] == '-')
		i++;
	while (checkArg[i])
	{
		if (checkArg[i] >= 48 && checkArg[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

/**
 * printErr - Prints if there is an error and frees all things
 * @head: Linked list.
 * @fd: Pointer to a file.
 * @buffer: Buffer.
 * @lineCount: Number of the line.
 */
void printErr(stack_t **head, FILE *fd, char *buffer, unsigned int lineCount)
{
	fprintf(stderr, "L%d: usage: push integer\n", lineCount);
	free_all(head, fd, buffer);
	exit(EXIT_FAILURE);
}

/**
 * checkFunc - Checks for a function.
 * @command: Command to check.
 * Return: Depending of the function.
 */
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
	if (strcmp(command, "pstr") == 0)
		return (3);
	return (0);
}
