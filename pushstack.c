#include "monty.h"

/**
 * push_stack - This function pushes integers into the stack
 *
 * @stack: stack
 * @num: The number to push
 * Return: The new node created
 */
stack_t *push_stack(stack_t **stack, int num)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		free_stack(stack);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
	return (new_node);
}
