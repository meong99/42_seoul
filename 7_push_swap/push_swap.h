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
#define ROTATE 2

typedef struct	s_node
{
	struct s_node *previous;
	struct s_node *next;
	int	value;
}	t_node;

typedef struct	s_stack
{
	int num;
	int *low_num;
	int stack_block;
	int stack_type;
	int *arr_num;
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
void	sa_b(t_stack *stack);
int	pa_b(t_stack *send_stack, t_stack *receive_stack);
void	ra_b(t_stack *stack);
void	rra_b(t_stack *stack);
int	rotate_command(t_stack *stack, t_stack *other_stack);
int	swap_command(t_stack *stack_a, t_stack *stack_b);

/*
** sort.c
*/
int	push_sort(int stack_range, t_stack *stack, t_stack *other_stack, int *arr_num);

void temp_print(t_stack *stack, t_stack *other_stack);
#endif
