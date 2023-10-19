#include "monty.h"
/**
 * add_dnodeint - adds a node to the beginning of the list
 * @head: the pointer to the node
 * @n: the value of the node
 *
 * Return: the new node added
*/
void add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp, *new_node;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
/**
 * add_dnodeint_end - adds a node at the end of the linked list
 * @head: the pointer to the node to be added
 * @n: the integer to be added
 *
 * Return: the new node added
*/
void add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp, *tp;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(global.file);
		free(global.command);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	temp->next = NULL;
	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = temp;
	}
	else
	{
		tp = *head;
		while (tp->next != NULL)
		{
			tp = tp->next;
		}
		tp->next = temp;
		temp->prev = tp;
		*head = temp;
	}
}

/**
 * free_node -  frees the linked list
 * @head: the pointer to the first  node of the list
*/
void free_node(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
/**
 * dlistint_len - returns the length of a linked list
 * @h: the linked list to to check
 *
 * Return: the length of the linked list
*/
int dlistint_len(const stack_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
