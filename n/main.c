#include "monty.h"
global_t glob = {0, 0};

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		instructions(av[1]);
	return (0);
}

void openFile(char *filename, instruction_t instruction[])
{
	size_t n = 0;
	stack_t *head = NULL;
	unsigned int lineCount = 1, flag = 0;
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
		chars = getline(&buffer, &n, fd);
		if (chars == EOF)
			break;
		if (buffer[chars - 1] == '\n')
			buffer[chars - 1] = '\0';
		command = strtok(buffer, " ");
		if (command == NULL)
		{
			lineCount++;
			continue;
		}
		checkArg = strtok(NULL, " ");
		if (checkArg != NULL && _isdigit(checkArg) == 1)
			glob.argument = atoi(checkArg);
		else
		{
			if (checkFunc(command) == 1)
				printErr(&head, fd, buffer, lineCount);
			else if (checkFunc(command) == 2)
			{
				lineCount++;
				continue;
			}
			else if (checkFunc(command) == 3)
				flag++;
		}
		head = cFunc(&head, lineCount, instruction, command);
		if (flag == 0 && head == NULL)
			free(buffer), closeFile(fd), exit(EXIT_FAILURE);
		flag = 0, lineCount++;
	}
	free_all(&head, fd, buffer);
}

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

void free_all(stack_t **head, FILE *fd, char *buffer)
{
	free_list(*head);
	closeFile(fd);
	free(buffer);
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
