#include "shell.h"

/**
 * prompt - Display Shell Prompt
 */
void prompt(void)
{
	PRINTER("$ ");
}
/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @input:User Input
 * @counter:Simple Shell Count Loop
 * @argv:Program Name
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}

/**
* _getchar - gets a char
* Return: a  character
*/
char _getchar(void)
{
	char *character, buffer[1];
	int descript = 0;

	descript = read(STDIN_FILENO, buffer, 1);

	if (descript > 0)
	{
		character = buffer;
		return (*character);
	}
	else if (descript == -1)
	{
		perror("Error");
		return (0);
	}
	return (EOF);
}

/**
* _getline - get a line
* Return: input pointer
*/
char *_getline(void)
{
	char *input = NULL;
	int p, index = 0, buffer_size = BUFFER_SIZE;

	input = _calloc(buffer_size, sizeof(char));

	if (!input)
	{
		perror("Error");
		return (NULL);
	}
	while (1)
	{
		p = _getchar();
		if (p == EOF)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (p == '\n')
		{
			input[index] = '\0';
			return (input);
		}
		input[index] = p;
		index++;
	}
	return (input);
}
