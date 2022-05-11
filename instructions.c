#include "monty.h"

/**
 * instructions - Struct initialization.
 * @filename: Name of the file.
 */
void instructions(char *filename)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pint", pint},
		{"pall", pall},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"queue", queue},
		{"stack", stack},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}};
	openFile(filename, instruction);
}

/**
 * cFun - Calls the corresponding function.
 * @h: Linked list.
 * @line: Number of the line.
 * @inst: Struct of functions.
 * @cmd: Command.
 * Return: Updated linked list or NULL if it failed.
 */
stack_t *cFunc(stack_t **h, unsigned int line, instruction_t inst[], char *cmd)
{
	int i = 0;

	for (i = 0; inst[i].opcode; i++)
	{
		if (strcmp(inst[i].opcode, cmd) == 0)
		{
			inst[i].f(h, line);
			return (*h);
		}
	}
	if (inst[i].opcode == NULL)
	{
		dprintf(2, "L%d: unknown instruction %s\n", line, cmd);
		exit(EXIT_FAILURE);
	}
	return (NULL);
}

/**
 * queue - Changes the behaviour of the program.
 * @head: Linked list.
 * @lineCount: Number of the line.
 */
void queue(stack_t **head, unsigned int lineCount)
{
	(void)head;
	(void)lineCount;
	glob.mode = 1;
}

/**
 * stack - Changes the behaviour of the program.
 * @head: Linked list.
 * @lineCount: Number of the line.
 */
void stack(stack_t **head, unsigned int lineCount)
{
	(void)head;
	(void)lineCount;
	glob.mode = 0;
}
