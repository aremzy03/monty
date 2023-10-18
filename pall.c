#include "monty.h"
/**
 * _pall - prints the contents of the linked list
 * @head: the pointer to the first node
 * @line_number: the line number of the function
*/
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	(void)line_number;
	h = *head;
	if (h == NULL)
		return;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * _pint - prints the first element of a stack
 * @head: pointer to list
 * @line_number: the line number
*/
void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	h = *head;
	if (h != NULL)
	{
		printf("%d\n", h->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
}
/**
 * _nop - does nothing
 * @head: pointer to list
 * @line_number: the line number
*/
void _nop(stack_t **head, unsigned int line_number)
{
	(void)*head;
	(void)line_number;
}
