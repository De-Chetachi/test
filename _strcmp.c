#include "s_shell.h"

/**
* _strcmp - compares two strings
* @s1: Pointer to the first string
* @s2: Pointer to the second string
* Return: The difference
*/

int	_strcmp(char	*s1,	char	*s2)
{

	while	(*s1 != '\0' && *s2 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return	(*s1 - *s2);
}
