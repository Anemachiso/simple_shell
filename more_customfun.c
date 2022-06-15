#include "shell.h"

/**
 * _atoi - a function that converts string to integer
 * @s: An input string
 * Return: integer from conversion
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			null_flag = 1;
			total = total * 10 + *s - '0';
		}

		else if (null_flag)
			break;
		s++;
	}

	if (sign < 0)
		total = (-total);

	return (total);
}

/**
* _strdup - returns pointer to duplicated string
* @str: the string to be copied
* Return: v0id
*/
char *_strdup(char *str)
{
	int x, n;
	char *dupe;

	if (!str)
		return (NULL);

	n = _strlen(str) + 1;

	dupe = _calloc(n, sizeof(char));
	if (!dupe)
		return (NULL);
	for (x = 0; x < n; x++)
		dupe[x] = str[x];
	return (dupe);
}

/**
 * signal_to_handel - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
