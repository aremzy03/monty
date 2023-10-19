#include "monty.h"
/**
 * _pop - delets at beginning for stack and
 * at end for queue
 * @head: pointer to list
 * @line_number: the line number
*/
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
/**
 * _stack - changes the mode to stack
 * at end for queue
 * @head: pointer to list
 * @line_number: the line number
*/
void _stack(stack_t **head, unsigned int line_number)
{
	(void)*head;
	(void)line_number;
	global.mode = 0;
}
/**
 * _queue - changes the mode to queue
 * at end for queue
 * @head: pointer to list
 * @line_number: the line number
*/
void _queue(stack_t **head, unsigned int line_number)
{
	(void)*head;
	(void)line_number;
	global.mode = 1;
}
