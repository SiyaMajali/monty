#include "monty.h"

#define s "L%d: unknown instruction %s\n"

void Destroy(List *list)
{
	while (list->Size)
		List_Rem(list, NULL);
}

int main(int argc, char *argv[])
{
	FILE *fd;
	char *line = NULL;
	size_t len = 0, line_num;
	ssize_t nread;

	void (*Pointer_Function)(stack_t **, unsigned int);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	list.Fd = fd;
	line_num = 1;
	while ((nread = getline(&line, &len, fd)) != -1)
	{
		list.Solve_line = line;
		(list.inst_oper)[0] = strtok(line, "\t\n ");
		(list.inst_oper)[1] = strtok(NULL, "\t\n ");
		if ((list.inst_oper[0] && list.inst_oper[0][0] == '#'))
			continue;
		if (list.inst_oper[0])
		{
			Pointer_Function = get_op((list.inst_oper)[0]);
			if (Pointer_Function)
				Pointer_Function(NULL, line_num);
			else
			{
				char *string =  list.inst_oper[0];

				fprintf(stderr, s, (int)line_num, string);
				free(line), fclose(list.Fd);
				Destroy(&list), exit(EXIT_FAILURE);
			}
		}
		line_num++, free(line),	line = NULL, len  = 0;
	}
	fclose(fd), free(line), Destroy(&list);
	return (0);
}
