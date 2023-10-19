#include "monty.h"
/**
 * _exec - identifies commands and executes them
 * @command: the command to be executed
 * @node: the pointer to linked list
 * @count: counter for line number
 * @file: the program file
 *
 * Return: 1 if comment found
*/
int _exec(char *command, stack_t **node, unsigned int count, FILE *file)
{
	instruction_t cmd[] = {
		{"push", _push}, {"pop", _pop}, {"pall", _pall}, {"nop", _nop},
		{"pint", _pint}, {"swap", _swap}, {"add", _add}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"stack", _stack}, {"queue", _queue},
		{NULL, NULL}
	};
	int i = 0;
	char *code;

	code = strtok(command, " \n\t");
	if (code == NULL || code[0] == '#')
	{
		return (0);
	}
	global.arg = strtok(NULL, " \n\t");
	while (cmd[i].opcode && code)
	{
		if (strcmp(code, cmd[i].opcode) == 0)
		{
			cmd[i].f(node, count);
			return (0);
		}
		i++;
	}
	if (code && cmd[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, code);
		fclose(file);
		free(command);
		free_node(*node);
		exit(EXIT_FAILURE);
	}
	return (1);
}
