#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command in the Monty bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack)) /* If stack is empty */
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n); /* Print the value at the top of the stack */
}

