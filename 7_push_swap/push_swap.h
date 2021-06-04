#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

/*
**
*/
/*
**
*/
#include <stdio.h>
#include <time.h>
/*
**
*/
/*
**
*/

#define STACK_A 1
#define STACK_B -1
#define SWAP 1
#define PUSH 2
#define ROTATE 3
#define R_ROTATE 4

typedef struct	s_node
{
	struct s_node *previous;
	struct s_node *next;
	int	value;
}	t_node;

typedef struct	s_stack
{
	int num;
	int stack_block;
	int stack_type;
	int *arr_num;
	int *sorting_count;
	int command;
	t_node *top;
	t_node *bottom;
}	t_stack;

/*
** push_swap
*/
int	new_node(t_stack *stack, int num);

/*
** swap_stack.c
*/
int	sa_b(t_stack *stack);
int	pa_b(t_stack *send_stack, t_stack *receive_stack);
int	ra_b(t_stack *stack);
int	rra_b(t_stack *stack);

/*
** sort.c
*/
int	push_sort(int stack_range, t_stack *stack, t_stack *other_stack, int *arr_num);

void temp_print(t_stack *stack, t_stack *other_stack);
#endif
