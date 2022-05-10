#include "monty.h"

int main(int ac, char *av[])
{
	stack_t *list;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		list = openfile(av[1]);
		list = list;
	}
	return (0);
}

stack_t *openfile(char *filename)
{
	size_t n = 0;
	stack_t *list = NULL;
	int chars = 0;
	char *buffer = NULL, *token;
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
		if (chars == -1)
		{
			free(buffer);
			break;
		}
		printf("chars:%d\nbuffer:%s.\n", chars, buffer);
		token = strtok(buffer, " ");
		printf("\ntoken:%s.\n\n", token);
	}
	return (list);
}
