#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_file_ilyass(char *file_name);
int parse_line_ilyass(char *buffer, int line_number, int format);
void read_file_ilyass(FILE *filedescriptor);
int len_chars(FILE *);
void find_func_ilyass(char *opcode, char *value, int line_number, int format);

/*Stack operations*/
stack_t *create_node-ilyass(int number);
void free_nodes_ilyass(void);
void print_stack_ilyass(stack_t **, unsigned int);
void add_to_stack_daaif(stack_t **, unsigned int);
void add_to_queue_ilyass(stack_t **, unsigned int);

void call_fun_ilyass(op_function, char *, char *, int, int);

void print_top_ilyass(stack_t **, unsigned int);
void pop_top_ilyass(stack_t **, unsigned int);
void nop_ilyass(stack_t **, unsigned int);
void swap_nodes_ilyass(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_nodes_ilyass(stack_t **, unsigned int);
void sub_nodes_ilyass(stack_t **, unsigned int);
void div_nodes-ilyass(stack_t **, unsigned int);
void mul_nodes_ilyass(stack_t **, unsigned int);
void mod_nodes_ilyass(stack_t **, unsigned int);

/*String operations*/
void print_char_ilyas(stack_t **, unsigned int);
void print_str_ilyass(stack_t **, unsigned int);
void rotl_ilyass(stack_t **, unsigned int);

/*Error hanlding*/
void err_ilyas(int error_cd, ...);
void more_err_ilyas(int error_cd, ...);
void string_err_ilyas(int error_cd, ...);
void rotr_ilyass(stack_t **, unsigned int);

#endif
