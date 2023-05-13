#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command in the Monty bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !((*stack)->next)) /* If stack has less than two elements */
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *stack; /* Store the top node in a temporary variable */
	stack_t *next = top->next; /* Store the second node in a temporary variable */

	top->prev = next; /* Set the prev pointer of the top node to the second node */
	top->next = next->next; /* Set the next pointer of the top node to the third node (if exists) */
	next->prev = NULL; /* Set the prev pointer of the second node to NULL */
	next->next = top; /* Set the next pointer of the second node to the top node */

	if (top->next) /* If there is a third node */
		top->next->prev = top; /* Set its prev pointer to the top node */

	*stack = next; /* Set the head of the stack to the second node */
}
