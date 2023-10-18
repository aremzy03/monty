#include "monty.h"
/**
 * _add - adds the first and second of the stack
 * @head: the pointer to the list
 * @line_number: the line number
*/
void _add(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int result, length;

	h = *head;
	length = dlistint_len(h);
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	result = h->n + h->next->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
/**
 * _sub - substracts the first and second of the stack
 * @head: the pointer to the list
 * @line_number: the line number
*/
void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int result, length;

	h = *head;
	length = dlistint_len(h);
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	result = abs(h->n - h->next->n);
	h->next->n = result;
	*head = h->next;
	free(h);
}
/**
 * _div - divides the first and second of the stack
 * @head: the pointer to the list
 * @line_number: the line number
*/
void _div(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int result, length;

	h = *head;
	length = dlistint_len(h);
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	result = h->n / h->next->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
/**
 * _mul - multiplies the first and second of the stack
 * @head: the pointer to the list
 * @line_number: the line number
*/
void _mul(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int result, length;

	h = *head;
	length = dlistint_len(h);
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	result = h->n * h->next->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
/**
 * _mod - finds the mod of first and second of the stack
 * @head: the pointer to the list
 * @line_number: the line number
*/
void _mod(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int result, length;

	h = *head;
	length = dlistint_len(h);
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	result = h->n % h->next->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
