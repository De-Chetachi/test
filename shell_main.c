#include "s_shell.h"

/**
 * main - A program that implements the shell 
 *
 * Return: 0 on success
 */

int main(void)
{
	char *prmt = "$ ";
	char *buff_ptr = NULL;
	size_t buff_len;
	int p, q, exit_status = 0;
	char **tok_arr = NULL;
	int tok_len, path_len;
	char *path, **path_arr, *olddir, *home;
	bool pipe = false;
	ssize_t bytes;

	path = _getenv("PATH", environ);
	path_arr = token_s(path, ":", &path_len);

	/*loop (display the prompt after each execution)*/
	while (7 && !pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe = true;
	/*print a prompt*/

		else if (isatty(STDIN_FILENO) == 1)
		{
			_putchar(prmt[0]);
			_putchar(prmt[1]);
		}

	/*get input from stdin*/
		bytes = getline(&buff_ptr, &buff_len, stdin);
		if (bytes == -1)
		{
			if (buff_ptr)
				free(buff_ptr);
			if (tok_arr)
				free_double(tok_arr);
			free_double(path_arr);
			perror("error getting string from command line");
			exit(EXIT_FAILURE);
		}
		if (bytes == 1 && buff_ptr[bytes - 1] == '\n')
			continue;
		buff_ptr[bytes - 1] = '\0';

		if (buff_ptr == NULL)
		{
			continue;
		}

	/*tokenize the string from stdin*/
		tok_arr = token_s(buff_ptr, " ", &tok_len);
		if (tok_arr[0] == NULL)
		{
			continue;
		}

	/*execute the command*/
		/*handle builtins*/
		if (_strcmp(tok_arr[0], "exit") == 0)
		{
			if (tok_len > 1)
			{
				exit_status = _atoi(tok_arr[1]);
				/* Get the exit status from the argument */
			}
			free(buff_ptr);
			free_double(tok_arr);
			free_double(path_arr);
			return (exit_status);
		}
		else if (_strcmp(tok_arr[0], "env") == 0)
		{

			/*print the environment variables*/
			p = 0;
			while (environ[p])
			{
				q = 0;
				while (environ[p][q])
				{
					_putchar(environ[p][q]);
					q++;
				}
				_putchar('\n');
				p++;
			}
		}
		else if (_strcmp(tok_arr[0], "cd") == 0)
		{
			if (tok_len == 1)
			{
				home = _getenv("HOME", environ);
				chdir(home);
			}

			else if (tok_len > 1)
			{
				if (_strcmp(tok_arr[1], "-") == 0)
				{
					olddir = _getenv("OLDPWD", environ);
					chdir(olddir);
				}

				if (chdir(tok_arr[1]) != 0)
				{
					perror("cd");
				}
			}

		}
		else
		{
			tok_arr[0] = handle_path(path_arr, tok_arr[0]);

			if (access(tok_arr[0], X_OK) == 0)
			{
				fork_exec(tok_arr, environ);
			}
			else
			{
				free_double(tok_arr);
				continue;
			}
		}

	}

	free_double(tok_arr);
	free_double(path_arr);
	free(buff_ptr);
	return (0);
}
