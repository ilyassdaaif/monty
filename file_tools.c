#include "monty.h"

/**
 * open_file_ilyass - opens a file
 * @f_n: the file namepath
 * Return: void
 */

void open_file_ilyass(char *f_n)
{
	FILE *fd = fopen(f_n, "r");

	if (f_n == NULL || fd == NULL)
		err(2, f_n);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file_ilyass - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file_ilyass(FILE *filedescriptor)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, filedescriptor) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse_line_ilyass - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opérationcode is stack. 1 if queue.
 */

int parse_line_ilyass(char *buffer, int line_number, int format)
{
	char *opérationcode, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opérationcode = strtok(buffer, delim);
	if (opérationcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opérationcode, "stack") == 0)
		return (0);
	if (strcmp(opérationcode, "queue") == 0)
		return (1);

	find_func(opérationcode, val, line_number, format);
	return (format);
}

/**
 * find_func_ilyass - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line_number: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func_ilyass(char *opcode, char *value, int line_number, int format)
{
	int i;
	int flage;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flage = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, line_number, format);
			flage = 0;
		}
	}
	if (flage == 1)
		err(3, line_number, opcode);
}


/**
 * call_function_ilyass - Calls the required function.
 * @function: Pointer to the function that is about to be called.
 * @opcode: string representing the opcode.
 * @value: string representing a numeric value.
 * @linenumber: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_function_ilyass(op_function function, char *opcode, char *value, int linenumber, int format)
{
	stack_t *node;
	int flage;
	int i;

	fg = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			fg = -1;
		}
		if (value == NULL)
			err(5, linenumber);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				err(5, linenumber);
		}
		node = create_node(atoi(value) * flage);
		if (format == 0)
			function(&node, linenumber);
		if (format == 1)
			add_to_queue(&node, linenumber);
	}
	else
		function(&head, linenumber);
}