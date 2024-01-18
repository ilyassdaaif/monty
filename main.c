#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argcounter: arguments count
 * @argvalue: list of arguments
 * Return: always 0
 */

int main(int argcounter, char *argvalue[])
{
	if (argcounter != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node_ilyass - Creates a node.
 * @number: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node_ilyass(int number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->number = number;
	return (node);
}

/**
 * free_nodes_ilyass - Frees nodes in the stack.
 */
void free_nodes_ilyass(void)
{
	stack_t *temporary;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temporary = head;
		head = head->next;
		free(temporary);
	}
}


/**
 * add_to_queue_ilyass - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @line_number: line number of the opcode.
 */
void add_to_queue_ilyass(stack_t **new_node, __attribute__((unused))unsigned int line_number)
{
	stack_t *temporary;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temporary = head;
	while (temporary->next != NULL)
		temporary = temporary->next;

	temporary->next = *new_node;
	(*new_node)->prev = temporary;

}