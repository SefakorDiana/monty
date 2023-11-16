#include "monty.h"

/**
 * stack_length - A func that calculates the length
 * of the stack
 *
 * @s: stack
 * Return: length of area
 */
int stack_length(const stack_t *s)
{
	int len;

	len = 0;
	while (s)
	{
		len++;
		s = s->next;
	}
	return (len);
}
