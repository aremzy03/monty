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
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
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
/**
 * _pchar - converts the first stack to character
 * @head: pointer to list
 * @line_number: the line number
*/
void _pchar(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int chr;

	h = *head;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	chr = h->n;
	if (chr >= 32 || chr <= 122)
	{
		printf("%c\n", chr);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pstr - converts the first stack to character
 * @head: pointer to list
 * @line_number: the line number
*/
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	(void)line_number;
	h = *head;
	if (h == NULL)
		return;
	while (h != NULL)
	{
		if (h->n == 0)
			break;
		if (h->n >= 31 || h->n <= 122)
		{
			printf("%c", h->n);
		}
		else
			break;
		h = h->next;
	}
	printf("\n");
}
