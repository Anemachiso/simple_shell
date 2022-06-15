#include "shell.h"

/**
* main - simple shell main function
* @argc: argument count
* @argv: argument value
* @envp: array of environment variable
* Return: 0
*/
int main(int argc, char **argv[], char *envi[])
{
	char *input, **cmd;
	int status = 1;

	(void) argc;
	(void) argv;

	signal(SIGINT, signal_to_handel);
	do {
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		cmd = splitline(input);
		status = execute_builtin(cmd, envi);
		free(input);
		free(args);
	} while (status);

	return (0);
}
static char *builtin[] = {"cd", "env", "exit"};
static int built_num = 3;
int (*builtin_function[]) (char **) = {&_cd, &_env, &_builtinexit};
/**
* execute_builtin - gets the builtins and executes them
* @cmd: cmd ptr
* @env: env var
* Return: what the function returns
*/
int execute_builtin(char **cmd, char **env)
{

	int index, exit_ret, exit_args = 0;

	if (*cmd == NULL)
		return (1);
	for (index = 0; index < built_num; index++)
	{
		if (_strcmp(cmd[0], "env") == 0)
			return (_env(env));
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_ret = _builtinexit(cmd);
			exit_args = _atoi(cmd[1]);
			if (exit_args < 0)
			{
				write(1, "Illegal exit code", 23);
				free(args);
				exit(EXIT_FAILURE);
			}
			if (exit_ret == -1)
				perror("Error on exit");
			else
			{
				free(cmd[0]);
				free(cmd);
				exit(exit_ret);
			}
		}
		if (_strcmp(cmd[0], builtin[index]) == 0)
		return ((*builtin_function[index])(cmd));
	}
	return (_execute(cmd));
}

/**
* _execute - handles executing the files
* @cmd: cmd ptr
* Return: 1 on success, 0 on failure
*/
int _execute(char **cmd)
{
	int status, execute_status;
	pid_t process_id;

	if (*cmd == NULL)
		return (1);

	process_id = fork();

	if (process_id == 0)
	{
		if (_strchr(cmd[0], '/') != NULL)
		{
			execute_status = execve(cmd[0], cmd, environ);
			if (execute_status == -1)
			{
				perror("Execution error");
				return (0);
			}
		}
		else
			return (carvePath(cmd));
	}
	else if (process_id < 0)
		perror("Failure to fork");
	else
		wait(&status);
	return (1);
}
