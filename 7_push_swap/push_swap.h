#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

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

/*
** push_swap
*/
int	new_node(t_stack *stack, int num);

/*
** swap_stack.c
*/
int	swap_f_s(t_node *first, t_node *second, t_stack *stack);
int	push_stack(t_stack *send_stack, t_stack *receive_stack);
int	rotate_stack(t_stack *stack);
int	reverse_rotate_stack(t_stack *stack);

#endif
