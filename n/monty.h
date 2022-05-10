#ifndef MONTY_H
#define MONTY_H

/* Global var */

extern int argument;

/* Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/* Struct */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Functions */

void instructions(char *filename);
void openFile(char *filename, instruction_t instruction[]);
stack_t *cFunc(stack_t **, unsigned int, instruction_t[], char *);
void push(stack_t **head, unsigned int line);
void free_list(stack_t *head);
stack_t *add_node_end(stack_t **head);
void pint(stack_t **head, unsigned int line);
void pall(stack_t **head, unsigned int line);
void closeFile(FILE *fd);

#endif /* MONTY_H */
