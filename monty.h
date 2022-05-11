#ifndef MONTY_H
#define MONTY_H

/* Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/* Structs */

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue).
 * @n: Integer.
 * @prev: Points to the previous element of the stack (or queue).
 * @next: Points to the next element of the stack (or queue).
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO.
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

/* Global var */

/**
 * struct global_s - Global structure
 * @argument: Argument
 * @mode: Indicates the behaviour of the program
 * @pop: pop.
 */
typedef struct global_s
{
	int argument;
	int mode;
	int pop;
} global_t;
extern global_t glob;

/* Functions */

void closeFile(FILE *fd);
int checkFunc(char *command);
int _isdigit(char *checkArg);
void free_list(stack_t *head);
void instructions(char *filename);
stack_t *add_node(stack_t **head);
stack_t *add_node_end(stack_t **head);
void delete_first_node(stack_t **head);
stack_t *add_node_start(stack_t **head);
void mod(stack_t **head, unsigned int lineCount);
void pop(stack_t **head, unsigned int lineCount);
void mul(stack_t **head, unsigned int lineCount);
void add(stack_t **head, unsigned int lineCount);
void sub(stack_t **head, unsigned int lineCount);
void pint(stack_t **head, unsigned int lineCount);
void pall(stack_t **head, unsigned int lineCount);
void push(stack_t **head, unsigned int lineCount);
void swap(stack_t **head, unsigned int lineCount);
void _div(stack_t **head, unsigned int lineCount);
void rotl(stack_t **head, unsigned int lineCount);
void rotr(stack_t **head, unsigned int lineCount);
void pstr(stack_t **head, unsigned int lineCount);
void pchar(stack_t **head, unsigned int lineCount);
void stack(stack_t **head, unsigned int lineCount);
void queue(stack_t **head, unsigned int lineCount);
void free_all(stack_t **head, FILE *fd, char *buffer);
void openFile(char *filename, instruction_t instruction[]);
stack_t *cFunc(stack_t **, unsigned int, instruction_t[], char *);
void printErr(stack_t **head, FILE *fd, char *buffer, unsigned int lineCount);

#endif /* MONTY_H */
