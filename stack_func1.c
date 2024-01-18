#include "monty.h"


/**
 * add_to_stack_daaif - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add_to_stack_daaif(stack_t **new_node, __attribute__((unused))unsigned int line_number)
{
	stack_t_ilyass *temporary ;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temporary  = head;
	head = *new_node;
	head->next = temporary ;
	temporary->prev = head;
}


/**
 * print_stack_ilyass - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack_ilyass(stack_t **stack, unsigned int line_number)
{
	stack_t_ilyass *temporary;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temporary = *stack;
	while (temporary != NULL)
	{
		printf("%d\n", temporary->n);
		temporary = temporary->next;
	}
}

/**
 * pop_top_ilyass - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top_ilyass(stack_t **stack, unsigned int line_number)
{
	stack_t_ilyass *temporary;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	temporary = *stack;
	*stack = temporary->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temporary);
}

/**
 * print_top_ilyass - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top_ilyass(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
