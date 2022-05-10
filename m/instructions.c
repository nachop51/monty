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
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"rotl", rotl},
		{"rotr", rotr},
		/*{"pchar", pchar},
		{"pstr", pstr},*/
		{NULL, NULL}};
	openFile(filename, instruction);
}
