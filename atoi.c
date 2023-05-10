#include "monty.h"
/**
 * _atoi - checks user input's data type
 * @c: user input
 * Return: 1. Success 0. Failure
 */
int _atoi(char *c)
{
	char *aux = c;

	if (c == NULL)
		return (0);

	/* if negative move to next address */
	if (*aux == '-')
		aux++;

/* return 1. if digit is true and move to next address until null byte */
	while (*aux != '\0')
	{
		if (*aux < '0' || *aux > 9)
			return (0);
		return (1);
		aux++;
	}

}
