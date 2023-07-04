#include "s_shell.h"

/**
* token_s - tokenizes a string
* @str: String to be tokenised
* @delim: Pointer to delimeters
* @tok_size: Pointer to toksize
* Return: Pointer to an array of strings
*/
char **token_s(char *str, char *delim, int *tok_size)
{
	char **tokens = malloc(BUFF_SIZE * sizeof(char *));
	char store[BUFF_SIZE];
	char *str_cpy = _strcpy(store, str);
	char *token;
	int bytes = _strlen(delim);

	*tok_size = 0;
	token = _strstr(str_cpy, delim);

	while (token != NULL && *tok_size < BUFF_SIZE)
	{
		*token = '\0';
		tokens[*tok_size] = _strdup(str_cpy);
		(*tok_size)++;
	       str_cpy = token + bytes;
	       token = _strstr(str_cpy, delim);
	}
	tokens[*tok_size] = _strdup(str_cpy);
	(*tok_size)++;
	tokens[*tok_size] = NULL;
	return (tokens);
}
