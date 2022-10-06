#include "monty.h"
/**
 * _nop- function does anything
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
void _nop(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	(void)lin_num;
}
/**
 * _pchar- prints the char at the top of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
void _pchar(stack_t **stack, unsigned int lin_num)
{
	(void)stack;

	if (list.Size)
	{
		if (list.Head->n > 0 && list.Head->n <= 127)
			printf("%c\n", list.Head->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lin_num);
			free(list.Solve_line), fclose(list.Fd);
			Destroy(&list), exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lin_num);
		free(list.Solve_line), fclose(list.Fd);
		Destroy(&list), exit(EXIT_FAILURE);
	}
}
/**
 * pstr_stack- prints the str from  a list
 * @stack: double pointer to doubly linked list
 * Return: none
 */
void pstr_stack(stack_t *stack)
{
	if (stack)
	{
		if (stack->n > 0 && stack->n < 127)
		{
			printf("%c", stack->n);
			pstr_stack(stack->next);
		}
	}
}
/**
 * _pstr- prints the str of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
void _pstr(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	(void)lin_num;
	if (list.Size)
	{
		pstr_stack(list.Head);
		printf("\n");
	}
	else
		printf("\n");
}

/**
 * _rotl - The opcode rotl rotates the stack to the top.
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 */

void _rotl(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	(void)lin_num;

	if (list.Size > 1)
	{
		stack_t *Element;

		Element         = list.Head;
		list.Head       = list.Head->next;
		list.Head->prev = Element->prev;

		Element->next   = list.Tail->next;
		Element->prev   = list.Tail;
		list.Tail->next = Element;
		list.Tail       = Element;
	}
}
