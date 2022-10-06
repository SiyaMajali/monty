#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;
/**
 * struct List_ - structure to keep data
 * @Head: pointer to head of structure
 * @Size: Size of list
 * @Tail: function to tail of structure
 * @inst_oper:token of strtok
 * @Fd: file descriptor
 * @Solve_line: free the memory from the line
 */
typedef struct List_
{
	int Size;
	struct stack_s *Head;
	struct stack_s *Tail;
	char *inst_oper[2];
	FILE *Fd;
	char *Solve_line;
} List;

/*
 * Macros
 */

#define List_Size(list)   ((list)->Size)
#define List_Next(list)   ((list)->next)
#define list_Head(list)   ((list)->head)
#define List_Tail(list)   ((list)->Tail)

/*
 * Function of the data structure.
 */

int List_Ins_Next(List *list, stack_t *Element, int Data);
int Push_Stack(List *list, int Data);
int Push_Queue(List *list, int Data);
void Pall(stack_t *Element);
int List_Rem(List *list, stack_t *Element);
int Pop_Stack(List *list);
int Pop_Queue(List *list);
void Destroy(List *list);
/* extern variables*/

List list;

/*fn tokenaze and, open and read file*/

void (*get_op(char *inst_oper))(stack_t **stack, unsigned int lin_num);

/* functions to instructions*/
void _push(stack_t **stack, unsigned int lin_num);
void _pop(stack_t **stack, unsigned int lin_num);
void _pall(stack_t **stack, unsigned int lin_num);
void _pint(stack_t **stack, unsigned int lin_num);
void _swap(stack_t **stack, unsigned int lin_num);
void _sub(stack_t **stack, unsigned int lin_num);
void _add(stack_t **stack, unsigned int lin_num);
void _mul(stack_t **stack, unsigned int lin_num);
void _mod(stack_t **stack, unsigned int lin_num);
void _div(stack_t **stack, unsigned int lin_num);
void _pchar(stack_t **stack, unsigned int lin_num);
void _pstr(stack_t **stack, unsigned int lin_num);
void _rotl(stack_t **stack, unsigned int lin_num);
void _nop(stack_t **stack, unsigned int lin_num);
void _rotr(stack_t **stack, unsigned int lin_num);
#endif
