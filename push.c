#include "monty.h"
/**
 * _push - add a number to the beginning in stack and
 * to the end in queue
 * @head: the pointer to the linked list
 * @line_number: the line number of command
*/
void _push(stack_t **head, unsigned int line_number)
{
	int num = atoi(global.arg), i = 0, check = 0;

	if (global.arg)
	{
		if (global.arg[0] == '-')
			i++;
		for (; global.arg[i] != '\0'; i++)
		{
			if (global.arg[i] > '9' || global.arg[i] < '0')
				check = 1;
		}
		if (check == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(global.file);
			free(global.command);
			free_node(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	if (global.mode == 0)
	{
		add_dnodeint(head, num);
	}
	else if (global.mode == 1)
	{
		add_dnodeint_end(head, num);
	}
}
/**
 * _swap - swaps the firs and second element
 * @head: pointer to list
 * @line_number: the line number
*/
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len, tmp;

	h = *head;
	len = dlistint_len(h);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	tmp = h->n;
	h->n = h->next->n;
	h->next->n = tmp;
}
