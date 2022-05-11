#include "monty.h"

/**
 * instructions - Struct initialization
 * @filename: Name of the file
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

void queue(stack_t **head, unsigned int lineCount)
{
	(void)head;
	(void)lineCount;
	glob.mode = 1;
}

void stack(stack_t **head, unsigned int lineCount)
{
	(void)head;
	(void)lineCount;
	glob.mode = 0;
}
