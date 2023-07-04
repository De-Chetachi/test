#ifndef S_SHELL_H
#define S_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#define BUFF_SIZE 1024

extern char **environ;

char    *_strcat(char   *dest,  char    *src);
char	*_strcpy(char *dest, char *src);
char	*_strstr(char *haystack, char *needle);
char **token_s(char *str, char *delim, int *tok_size);
int _putchar(char c);
char **tokarr(char *buff_ptr);
char *read_line(char **line_ptr, size_t *line_len);
int _strncmp(char *s, char *s2, int n);
int _strcmp(char *s1, char *s2);
int	_strlen(char	*s);
char	*_strdup(char *str);
char **path_append(char **path_arr, char *cmd);
char *cmd_status(char **cmd_arr);
char *handle_path(char **path_arr, char *cmd);
char *_getenv(char *env_name, char **ev);
pid_t fork_exec(char **cdl_arr, char **envp);
void free_double(char **vector);
int     _atoi(char *s);

#endif
