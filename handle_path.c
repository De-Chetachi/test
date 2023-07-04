#include "s_shell.h"
/**
* path_append - apends the command to path
* @path_arr: The array of paths
* @cmd: The command
* Return: Pointer to an array of strings
*/
char **path_append(char **path_arr, char *cmd)
{
	int i, k, arr_len, cmd_len, path_len;
	char **cmd_arr = NULL;
	char *path_temp;

	i = 0;
	arr_len = 0;
	while (path_arr[i] != NULL)
	{
		arr_len++;
		i++;
	}
	arr_len++;
	cmd_arr = malloc(sizeof(char *) * arr_len);
	if (cmd_arr == NULL)
	{
		perror("allocation failure");
		return (NULL);
	}
	k = 0;
	while (path_arr[k] != NULL)
	{
		path_len = _strlen(path_arr[k]);
		cmd_len = _strlen(cmd);
		path_temp = malloc(path_len + 1 + cmd_len + 1);
		if (path_temp == NULL)
		{
			perror("allocation failure");
			if (cmd_arr)
				free(cmd_arr);
			return (NULL);
		}
		_strcpy(path_temp, path_arr[k]);
		_strcat(path_temp, "/");
		_strcat(path_temp, cmd);
		cmd_arr[k] = path_temp;
		k++;
	}
	cmd_arr[k] = NULL;
	return (cmd_arr);
}

/**
* cmd_status - checks for which command in the cmd_arr exists
* @cmd_arr: Pointer to an array of commands
* Return: The command that exists
*/

char *cmd_status(char **cmd_arr)
{
	struct stat st;
	int i;

	i = 0;
	while (cmd_arr[i])
	{
		if (stat(cmd_arr[i], &st) == 0)
		{
			return (cmd_arr[i]);
		}
		i++;
	}
	return (NULL);
}
/**
* handle_path - handles the path of a given command
* @path_arr: Pointer to the string of paths
* @cmd: The given command
* Return: An executable command or Null
*/

char *handle_path(char **path_arr, char *cmd)
{
	struct stat st;
	char **cmd_arr = NULL;
	char *executable_cmd = NULL;

	if (path_arr == NULL || cmd == NULL)
		return (NULL);

	if (stat(cmd, &st) == 0)
		return (cmd);

	cmd_arr = path_append(path_arr, cmd);

	if (cmd_arr == NULL)
		return (NULL);

	executable_cmd = _strdup(cmd_status(cmd_arr));
	if (executable_cmd == NULL)
	{
		perror("Error file status");
		if (cmd_arr)
			free_double(cmd_arr);
		return (NULL);
	}
	free_double(cmd_arr);
	return (executable_cmd);
}
