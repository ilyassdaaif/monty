#include "monty.h"

/**
 * print_char_ilyas - Prints the ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char_ilyas(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}

/**
 * print_str_ilyass - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str_ilyass(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *temporary;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temporary = *stack;
	while (temporary != NULL)
	{
		ascii = temporary->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temporary = temporary->next;
	}
	printf("\n");
}

/**
 * rotl_ilyass - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line-number: Interger representing the line number of of the opcode.
 */
void rotl_ilyass(stack_t **stack, __attribute__((unused))unsigned int line-number)
{
	stack_t *temporary;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temporary = *stack;
	while (temporary->next != NULL)
		temporary = temporary->next;

	temporary->next = *stack;
	(*stack)->prev = temporary;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr_ilyass - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line-number: Interger representing the line number of of the opcode.
 */
void rotr_ilyass(stack_t **stack, __attribute__((unused))unsigned int line-number)
{
	stack_t *temporary;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temporary = *stack;

	while (temporary->next != NULL)
		temporary = temporary->next;

	temporary->next = *stack;
	temporary->prev->next = NULL;
	temporary->prev = NULL;
	(*stack)->prev = temporary;
	(*stack) = temporary;
}
