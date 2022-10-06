#include "monty.h"


void _push(stack_t **stack, unsigned int lin_num)
{
	int index = 0;
	(void)stack;

	if (list.inst_oper[1])
	{
		if (list.inst_oper[1][index] == '-')
		{
			if (isdigit(list.inst_oper[1][1]))
				index++;
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", lin_num);
				free(list.Solve_line), fclose(list.Fd);
				Destroy(&list), exit(EXIT_FAILURE);
			}
		}

		while ((list.inst_oper)[1][index])
		{
			if (isdigit((list.inst_oper)[1][index]))
				index++;
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", lin_num);
				free(list.Solve_line), fclose(list.Fd);
				Destroy(&list), exit(EXIT_FAILURE);
			}
		}
		Push_Stack(&list, atoi((list.inst_oper)[1]));
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", lin_num);
		free(list.Solve_line), fclose(list.Fd),	Destroy(&list);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pall- prints the first element at the top of the stack
 * @stack: double pointer to doubly linked list
 * @lin_num: number of line to be analize
 * Return: none
 */
void _pall(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	(void)lin_num;

	if (list.Size)
		Pall(list.Head);
}

void _pint(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	if (list.Size)
		printf("%d\n", list.Head->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lin_num);
		free(list.inst_oper[0]);
		fclose(list.Fd);
		Destroy(&list);
		exit(EXIT_FAILURE);
	}
}


void _pop(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	if (list.Size)
		Pop_Stack(&list);
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lin_num);
		free(list.inst_oper[0]), fclose(list.Fd);
		Destroy(&list), exit(EXIT_FAILURE);
	}
}

void _swap(stack_t **stack, unsigned int lin_num)
{
	(void)stack;
	if (list.Size > 1)
	{
		int Number1, Number2;

		Number1 = Pop_Stack(&list);
		Number2 = Pop_Stack(&list);
		Push_Stack(&list, Number1);
		Push_Stack(&list, Number2);
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lin_num);
		free(list.inst_oper[0]), fclose(list.Fd), Destroy(&list);
		exit(EXIT_FAILURE);
	}
}
