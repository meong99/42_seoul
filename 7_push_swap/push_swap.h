#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct	s_node
{
	t_node *previous;
	t_node *next;
	int	num;
}	t_node;

typedef struct	s_stack
{
	t_node *top;
	t_node *bottom;
}	t_stack;

/*
** swap_stack.c
*/
int	f_s_swap(t_node *first, t_node *second, t_stack *stack);
int	push_stack(t_stack *stack_send, t_stack *stack_receive);
int	rotate_stack(t_stack *stack);
int	reverse_rotate_stack(t_stack *stack);

#endif
