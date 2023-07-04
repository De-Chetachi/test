#include "s_shell.h"

/**
  * fork_exec - This program creates a child process
  * @cdl_arr: The array of command argument
  * @envp: The environment variable
  *
  * Return: The PID of the child process or -1 on failure
  */

pid_t fork_exec(char **cdl_arr, char **envp)
{
	int status;
	char *cmd;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error creating child process");
		return (-1);
	}

	if (child_pid == 0)
	{
		if (cdl_arr)
		{
			cmd = cdl_arr[0];
			if (execve(cmd, cdl_arr, envp) == -1)
			{
				perror("Error executing cmd");
					return (-1);
			}
		}
	}
	else
	{
		wait(&status);
	}

	return (child_pid);
}
