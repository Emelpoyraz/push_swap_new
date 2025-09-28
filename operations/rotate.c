#include "push_swap.h"

static void rotate(t_node **stack)
{
    t_node *first;
    t_node *last;

    if(!stack || !*stack || !(*stack)->next)
        return;
    first = pop_front(stack);
    last = last_node(*stack);
    last->next = first;
    first->next = NULL;
}
void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}