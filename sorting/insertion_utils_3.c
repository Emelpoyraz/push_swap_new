#include "../include/push_swap.h"

/* ===== Execute the best move to insert chosen node from B → A ===== */
static void	rotate_both_forward(t_node **a, t_node **b,
			int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	rotate_both_backward(t_node **a, t_node **b,
			int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	rotate_single_a(t_node **a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
}

static void	rotate_single_b(t_node **b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}

void	execute_best_move(t_node **a, t_node **b, t_node *target)
{
	int	pos_a;
	int	pos_b;
	int	cost_a;
	int	cost_b;

	pos_a = find_insert_position(*a, target->value);
	pos_b = node_index(*b, target);
	cost_a = rotation_cost(*a, pos_a);
	cost_b = rotation_cost(*b, pos_b);
	rotate_both_forward(a, b, &cost_a, &cost_b);
	rotate_both_backward(a, b, &cost_a, &cost_b);
	rotate_single_a(a, &cost_a);
	rotate_single_b(b, &cost_b);
	pa(a, b);
}
