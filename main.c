#include "monty.h"
/**
 *
 */
int main(int ac, char **av)
{
	if (ac == 2)
		handle_function(av[1]);
	else
	{
		printf(stderr, "USAGE: monty filename\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
/** PSEUDO CODE TO DIVDE AND CONQUER **/
/** int push(int arg)
{
	//checks its an int and pushes
	if (!(arg < 48 && arg > 58) || arg == NULL)
	{
		printf("L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

}

int pall(int index, char *argv[])
{
	//prints all from top to bottom
	int i = index;
	if (arr[i] == NULL)
		exit;
for (i > -1; i <= arr[0]; i--)
	printf("%i\n", i);
	*previous;
}

int pint(int *top)
{
	//prints top
	if (*top == NULL)
		printf("L<line_number>: usage: push integer\n");
                exit(EXIT_FAILURE);
	else
		printf("%i\n", *top);
}

int pop(int *top)
{
	//checks its on position top and removes element
}

int swap(int *top, int *top2, int argv)
{
	//swaps top elements
	if (argv > 2)
		printf("L<line_number>: usage: push integer\n");
                exit(EXIT_FAILURE);
}

int add(*top, *top2)
{
	//adds two top elements
} */
