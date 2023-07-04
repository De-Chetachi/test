#include "s_shell.h"

/**
 * _strcpy - copyies the string in the address pointed
 * to by the second int to the first int
 * @dest: First int
 * @src: Second int
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *pDest = dest;

	while (*src != '\0')
	{
		*pDest++ = *src++;
	}
	*pDest = '\0';
	return    (dest);
}
