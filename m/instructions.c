#include "monty.h"

/**
 * instructions - Struct initialization
 * @filename: Name of the file
 */
void *instructions(char *filename)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}};
	openfile(filename, instruction);
}
