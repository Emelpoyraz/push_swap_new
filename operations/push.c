#include "../include/push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*node;

	if (!b || !*b)
		return ;
	node = pop_front(b);
	push_front(a, node);
	write(1, "pa\n", 3);
}
void	pb(t_node **a, t_node **b)
{
	t_node	*node;

	if (!a || !*a)
		return ;
	node = pop_front(a);
	push_front(b, node);
	write(1, "pb\n", 3);
}
