#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

#define STACK_A 1
#define STACK_B -1

typedef struct	s_node
{
	struct s_node *previous;
	struct s_node *next;
	int	value;
}	t_node;

typedef struct	s_stack
{
	int num;
	t_node *top;
	t_node *bottom;
}	t_stack;

typedef struct	s_sort_mem
{
	int pivot;
	int	stack_type;
	int	stack_range;
	int	*arr_num;
	t_stack	*stack;
	t_stack	*other_stack;
}	t_sort_mem;


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

#endif
