#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command in the Monty bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack)) /* If stack is empty */
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *stack; /* Store the top node in a temporary variable */
	*stack = (*stack)->next; /* Move the head of the stack to the next node */

	if (*stack) /* If there is a new top node */
		(*stack)->prev = NULL; /* Set its prev pointer to NULL */

	free(temp); /* Free the previous top node */
}
