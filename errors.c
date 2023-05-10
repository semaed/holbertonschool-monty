#include "monty.h"
/**
 * open_err - handles open permission error
 * @file: name of file that failed
 * Return: exit status
 */
int open_err(char *file)
{
	printf(stderr, "Error: Can't open file %s\n", file);
	return (EXIT_FAILURE);
}
