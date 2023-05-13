#include "monty.h"

global_t *global_variable = NULL;/*Initialize the global variable pointer to NULL*/

/*Function prototype for execute_opcode*/
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number);

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;

	/*Check if the correct number of arguments is provided*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*Open the Monty bytecode file*/
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/*Allocate memory for the global variable*/
	global_variable = malloc(sizeof(global_t));
	if (!global_variable)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	global_variable->argument = NULL;

	/*Read the file line by line*/
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		/*Remove newline character if present*/
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		/*Tokenize the line to get the opcode and its argument (if any)*/
		opcode = strtok(line, " \t");/*Added '\t' to handle tab characters*/
		/*Check if the line is not empty or starts with a comment*/
		if (opcode != NULL && opcode[0] != '#')
		{
		global_variable->argument = strtok(NULL, " \t");

		/*Execute the opcode*/
		execute_opcode(&stack, opcode, line_number);
		}

		/*Free the line buffer and reset the length*/
		free(line);
		line = NULL;
		len = 0;
	}

	/*Close the file and free the memory*/
	fclose(file);
	free(line);
	free(global_variable);
	free_stack(stack);

	return (EXIT_SUCCESS);
}

/*Execute the appropriate opcode function based on the given opcode string*/
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{

	/*Define an array of opcodes and their corresponding functions*/
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	/*Iterate through the instructions array*/
	for (int i = 0; instructions[i].opcode; i++)
	{
		/*If the opcode matches execute its function*/
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	/*If the opcode is not found print an error message and exit*/
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
