#include "s_shell.h"
/**
* _atoi - converts a string to an integer
* @s: The pointer to the string to be converted
* Return: An integer
*/

int	_atoi(char *s)
{
	int	i,	uni,	sign;
	unsigned int	num;

	i	=	0;
	uni	=	0;
	sign	=	1;
	num	=	0;

	while	(s[i])
	{
		if	(s[i] == 45)
		{
			sign	=	sign	*	-1;
		}
		while	(s[i] >= 48 && s[i] <= 57)
		{
			uni	=	1;
			num	=	(num * 10)	+	(s[i] - 48);
			i++;
		}
		if	(uni == 1)
		{
			break;
		}
		i++;
	}
	num	=	num	*	sign;
	return	(num);
}
