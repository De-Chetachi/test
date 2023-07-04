#include "s_shell.h"
/**
* _getenv - gets the value of env_name from the working environment
* @env_name: The name of the path we are trying to get
* @ev: The working environment
* Return: The pointer to the required string
*/

char *_getenv(char *env_name, char **ev)
{
	int name_length = _strlen(env_name);
	char **ev_cpy;

	for (ev_cpy = ev; *ev_cpy != NULL; ev_cpy++)
	{
		if (_strncmp(env_name, *ev_cpy, name_length)
				== 0 && (*ev_cpy)[name_length] == '=')
		{
			return (&(*ev_cpy)[name_length + 1]);
		}
	}
	return (NULL);
}
