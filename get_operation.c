#include "monty.h"

void (*get_op(char *inst_oper))(stack_t **stack, unsigned int lin_num)
{
	int i = 0;
	instruction_t instructions_fun[] = {
		{"push",  _push},
		{"pall",  _pall},
		{"pint",  _pint},
		{"pop",   _pop},
		{"swap",  _swap},
		{"nop", _nop},
		{"sub",   _sub},
		{"add",   _add},
		{"mul",   _mul},
		{"div",   _div},
		{"mod",   _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	while (instructions_fun[i].opcode)
	{
		if (strcmp(inst_oper, instructions_fun[i].opcode) == 0)
			return (instructions_fun[i].f);
		i++;
	}
	return (NULL);
}
