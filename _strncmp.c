#include "s_shell.h"

/**
* _strncmp - compares two strings upto n bytes
* @s1: Pointer to the first string
* @s2: Pointer to the second string
* @n: Number of bytes to compare
* Return: 0 if the first n bytes are same, else -1
*/

int	_strncmp(char	*s1,	char	*s2, int n)
{
	int diff = 0;
	int i = 0;

	while	((*s1 != '\0' || *s2 != '\0') && i < n)
	{
		if (*s1 != *s2)
		{
			diff++;
		}
		s1++;
		s2++;
		i++;
	}
	if (diff != 0)
	{
		return (-1);
	}

	return	(diff);
}
