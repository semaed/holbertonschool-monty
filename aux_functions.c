#include "monty.h"
/**
 * _nop - placebo function
 * doesn't do anything...
 * @stack: doubly link struct
 * @line_number: instruction line
 * Return: nothing
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	printf("Good try! But this doesn't do anything:p %d\n", line_number);
	(*stack)->n = 0;
}
