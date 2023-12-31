#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 256
#define UNUSED __attribute__((unused))
extern int n;


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


/**
 * struct ErrorInfo_s - opcode and its error message
 * @fun_name: the opcode
 * @error_message: the corresponding message for each opcode
 */
typedef struct ErrorInfo_s
{
	const char *fun_name;
	const char *error_message;
} ErrorInfo_t;


/**
 * struct conditions_s - opcode and its check functions
 * @fun_name: the opcode
 * @check1: function to handle the right opcode check
 * @check2: function to handle the right opcode check
 */
typedef struct conditions_s
{
	const char *fun_name;
	int (*check1)(stack_t **stack, char *number, int num);
	int (*check2)(stack_t **stack, char *number, int num);
} conditions_t;

void free_stack(stack_t *head);
size_t stack_len(const stack_t *h);
void add_node_top(stack_t **stack, UNUSED unsigned int line_number);
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void pop(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void swap(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void add(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void nop(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void sub(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void mul(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void div_o(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void mod(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void pchar(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void (*get_op_func(char *op_name))(stack_t **, unsigned int);
int (*get_op_check(char *op_name, int check_num))(stack_t **, char *, int);
int isNotEmpty_st(stack_t **stack, UNUSED char *number, UNUSED int num);
int notShort_st(stack_t **stack, UNUSED char *number, UNUSED int num);
int isNumber(UNUSED stack_t **stack, char *number, UNUSED int num);
int div_by0(stack_t **stack, UNUSED char *number, UNUSED int num);
int isInAscii(stack_t **stack, UNUSED char *number, UNUSED int num);
void command_error(stack_t **stack, char *op_name,
		unsigned int line_number, FILE *file);
void command_error2(stack_t **stack, char *op_name,
		unsigned int line_number, FILE *file);
void file_error(int num, char *file);
void execute(stack_t **stack, unsigned int line_number,
		char *command, FILE *file, unsigned int *mode);
void monty(char *filename);


#endif
