#include "monty.h"

void _rotr(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	(void)lin_num;

	if (list.Size)
	{
		stack_t *tmp;

		tmp = list.Tail;
		tmp->next = list.Head;
		list.Head->prev = tmp;
		list.Tail = list.Tail->prev;
		tmp->prev->next = NULL;
		list.Head = tmp;
	}
}
