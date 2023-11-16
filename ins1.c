#include "monty.h"

/**
 * push - pushes an integer onto the stack
 *
 * @stack: stack
 * @line_number: The line number in the script where push is called.
 * @s: string
 * Return: (void)
 */
void push(stack_t **stack, unsigned int line_number,
		  __attribute__((__unused__)) const char *s)
{
	if (!_isdigit(s))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	push_stack(stack, atoi(s));
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 *
 * @stack: stack
 * @line_number: The line number where the push operation is called
 * @s: string
 * Return: (void)
 */
void pall(stack_t **stack, unsigned int line_number,
		  __attribute__((__unused__)) const char *s)
{
	(void)line_number;
	print_stack(*stack, -1);
}

/**
 * pint - Prints the value at the top of the stack.
 *
 * @stack: A pointer to the pointer to the stack.
 * @line_number: The line number where the pint operation is called.
 * @s: string
 * Return: (void)
 */
void pint(stack_t **stack, unsigned int line_number,
		  __attribute__((__unused__)) const char *s)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	print_stack(*stack, 1);
}
/**
 * pop - function that Removes the top element of the stack.
 *
 * @stack: stack
 * @line_number: The line number where the pop operation is called.
 * @s: string
 * Return: (void)
 */
void pop(stack_t **stack, unsigned int line_number,
		 __attribute__((__unused__)) const char *s)
{
	stack_t *node;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	node = pop_stack(stack);
	free(node);
}

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @stack: stack
 * @line_number: the current line number
 * @s: string
 * Return: (void)
 */
void swap(stack_t **stack, unsigned int line_number,
		  __attribute__((__unused__)) const char *s)
{
	stack_t *a, *b;

	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	a = pop_stack(stack);
	b = pop_stack(stack);
	push_stack(stack, a->n);
	push_stack(stack, b->n);
	free(a);
	free(b);
}
