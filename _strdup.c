#include "s_shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * @str: The pointer to the string
 * Return: A pointer to the array, or NULL if it fails
 */
char *_strdup(char *str)
{
	unsigned int i, len;
	char *ptr;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	ptr = (char *) malloc((len * sizeof(char)) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
	{
		ptr[i] = str[i];
	}
	return (ptr);
}
