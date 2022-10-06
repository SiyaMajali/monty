#include "monty.h"
 
int List_Ins_Next(List *list, stack_t *element, int Data)
{
	stack_t *new_element = NULL;

	new_element = (stack_t *)malloc(sizeof(stack_t));
	if (!new_element)
	{
		fprintf(stderr, "Error: malloc failed\n"), free(list->Solve_line);
		fclose(list->Fd), Destroy(list), exit(EXIT_FAILURE);
	}
	new_element->n = Data;
	if (!element)
	{
		if (!List_Size(list))
			list->Tail  = new_element;
		new_element->next = list->Head;
		if (!list->Head)
			new_element->prev = list->Head;
		else
		{
			new_element->prev = list->Head->prev;
			list->Head->prev = new_element;
		}
		list->Head = new_element;
	}
	else
	{
		new_element->next = element->next;
		new_element->prev = element;
		if (!element->next)
		{
			list->Tail = new_element;
			element->next = new_element;
		}
		else
		{
			element->next->prev = new_element;
			element->next = new_element;
		}
	}
	list->Size++;
	return (0);
}
 
void Pall(stack_t *element)
{
	if (element)
	{
		printf("%d\n", element->n);
		Pall(element->next);
	}
}
 
int List_Rem(List *list, stack_t *element)
{
	stack_t *Old_element = NULL;
	int Old_Number;

	if (!element)
	{
		Old_element  = list->Head;

		if (list->Head->next)
			list->Head->next->prev = NULL;
		list->Head             = list->Head->next;

		if (List_Size(list) == 1)
			list->Tail = NULL;
	}
	else
	{
		if (!element->next)
			list->Tail = element->prev;

		Old_element = element;

		if (element->prev)
		{
			element->next->prev = element->prev;
			element->prev->next = element->next;
		}
	if (List_Size(list) == 1)
		list->Head = NULL;
	}
	Old_Number = Old_element->n;
	free(Old_element);
	list->Size--;
	return (Old_Number);
}
 
int Pop_Stack(List *list)
{
	return (List_Rem(list, NULL));
}

 
int Pop_Queue(List *list)
{
	return (List_Rem(list, NULL));
}
