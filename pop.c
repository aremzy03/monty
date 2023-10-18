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
