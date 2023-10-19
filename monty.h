#ifndef MONTY_H
#define MONTY_H
  /*--------------------*/
 /* STANDARD LIBRARIES */
/*--------------------*/
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
  /*-------------------------*/
 /* STRUCTURES AND TYPEDEFS */
/*-------------------------*/
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

/**
 * struct globa_s - contains important global var
 * @file: the file name
 * @command: contains the command passed in the file
 * @mode: to change the mode from stack to queue
 * @node: a pointer to linked list
 * 
 * Description: these are global variables that
 * allows me to easily access them from anywhere
*/
typedef struct global_s
{
	FILE *file;
	char *command;
	char *arg;
	unsigned int mode;
} global_t;
   /*-----------------*/
  /* GLOBAL VARIABLE */
 /*-----------------*/
extern global_t global;
    /*-----------*/
   /* FUNCTIONS */
  /*-----------*/
int _exec(char *command, stack_t **node, unsigned int count, FILE *file);
void add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void _push(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _pall(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
void free_node(stack_t *head);
int dlistint_len(const stack_t *h);
#endif
