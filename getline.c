#include "shell.h"

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
