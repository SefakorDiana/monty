#include "monty.h"

/**
 * print_stack - This function prints n nodes inside
 * of the stack
 *
 * @st: stack
 * @n: number of nodes to be printed
 * Return: (void)
 */
void print_stack(const stack_t *st, int n)
{
	int iterator;

	iterator = 0;
	while (st && (n == -1 || iterator < n))
	{
		putnumber(st->n);
		st = st->next;
		iterator++;
	}
}
