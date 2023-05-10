all: main.c monty.h
	gcc -Wall -Werror -Wextra -pedantic *.c -o monty
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./monty
