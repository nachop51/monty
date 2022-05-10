#include "monty.h"
int argument = -1;

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		instructions(av[1]);
	}
	return (0);
}

void openFile(char *filename, instruction_t instruction[])
{
	size_t n = 0;
	stack_t *head = NULL;
	unsigned int lineCount = 1;
	int chars = 0;
	char *buffer = NULL, *checkArg, *command;
	FILE *fd;

	fd = fopen(filename, "r");
	if (!fd)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		chars = getline(&buffer, &n, fd); /*Primera linea*/
		if (buffer[chars - 1] == '\n')
			buffer[chars - 1] = '\0';
		if (chars == EOF)
		{
			free(buffer);
			break;
		}
		command = strtok(buffer, " ");
		if (command == NULL)
		{
			lineCount++;
			continue;
		}
		checkArg = strtok(NULL, " ");
		if (checkArg != NULL)
			argument = atoi(checkArg);
		else
			argument = -1;
		head = cFunc(&head, lineCount, instruction, command);
		lineCount++;
	}
	free_list(head);
	closeFile(fd);
}

void closeFile(FILE *fd)
{
	int i = 0;

	i = fclose(fd);
	if (i != 0)
	{
		dprintf(2, "Can't close file\n");
	}
}

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
