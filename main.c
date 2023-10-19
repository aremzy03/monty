#include "monty.h"
global_t global;
/**
 * main - a monty program compiler
 * @ac: number of arguements
 * @av: the command line arguements
 *
 * Return: Always Zero
*/
int main(int ac, char **av)
{
	stack_t *node = NULL;
	size_t size = 0;
	ssize_t read;
	char *command = NULL;
	FILE *file;
	unsigned int counter = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	global.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file\n");
		exit(EXIT_FAILURE);
	}
	while (read != -1)
	{
		counter++;
		read = getline(&command, &size, file);
		global.command = command;
		global.mode = 0;
		if (read > 0)
		{
			_exec(command, &node, counter, file);
		}
	}
	fclose(file);
	free(command);
	free_node(node);
	return (0);
}
