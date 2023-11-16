#include "monty.h"

/**
 * free_stack - Frees all nodes in a stack
 *
 * @stack: A pointer to a pointer to the top of the stack
 * Return: (void)
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp, *current;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
