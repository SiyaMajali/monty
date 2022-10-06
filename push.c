#include "monty.h"

int Push_Stack(List *list, int Data)
{
	return (List_Ins_Next(list, NULL, Data));
}

int Push_Queue(List *list, int Data)
{
	return (List_Ins_Next(list, List_Tail(list), Data));
}
