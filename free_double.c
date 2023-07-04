#include "s_shell.h"
/**
* free_double - frees a two dimensional array
* @vector: Pointer to array
* Return: Void
*/

void free_double(char **vector)
{
	int i;

	i = 0;
	while (vector[i])
	{
		free(vector[i]);
		i++;
	}
	free(vector);
}
