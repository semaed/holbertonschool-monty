#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command in the Monty bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !((*stack)->next)) /* If stack has less than two elements */
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *stack; /* Store the top node in a temporary variable */
	stack_t *next = top->next; /* Store the second node in a temporary variable */

	next->n += top->n; /* Add the value of the top node to the value of the second node */
	*stack = next; /* Set the head of the stack to the second node */
	next->prev = NULL; /* Set the prev pointer of the second node to NULL */

	free(top); /* Free the previous top node */
}
