#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

#define STACK_A 1
#define STACK_B -1
#define SWAP 1
#define ROTATE 2
#define CHECK_LOW 0
#define NEXT_RANGE 1
#define COUNT_ROTATE 2
#define TYPE_C 1
#define TYPE_I 0
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
** init.c
*/
int	new_node(t_stack *stack, int num);
int	create_list(t_stack *stack, int *arr_num, int num);
void	init_stack(t_stack *stack, int *arr_num, int *low_num, int type);

/*
** push_swap.c
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
** sorting.c
*/
void	sorting(t_stack *stack, t_stack *other_stack, int stack_range);
int	check_sorted(t_stack *stack);

/*
** sort.c
*/
int	quick_sort(int stack_range, t_stack *stack, t_stack *other_stack);
void temp_print(t_stack *stack, t_stack *other_stack);

/*
** util.c
*/
void	push_stack_a(t_stack *stack, t_stack *other_stack, int stack_range);
void	range_2(t_stack *stack);
void	range_3(t_stack *stack, t_stack *other_stack, int stack_range);

/*
**
*/
/*
**
*/
#include <stdio.h>
#include <time.h>
t_stack *aa;
t_stack *bb;
/*
**
*/
/*
**
*/

#endif
