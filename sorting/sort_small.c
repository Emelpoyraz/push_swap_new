#include "../include/push_swap.h"

static void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	sort_three(t_node **a)
{
	int f = (*a)->value;
	int s = (*a)->next->value;
	int t = (*a)->next->next->value;

	if (f > s && f > t)
		ra(a);
	else if (s > f && s > t)
		rra(a);

	if ((*a)->value > (*a)->next->value)
		sa(a);
}

static void	sort_four(t_node **a, t_node **b)
{
	int	index;

	index = find_min_index(*a);
	if (index == 1)
		ra(a);
	else if (index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (index == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

static void	sort_five(t_node **a, t_node **b)
{
	int	index;

	index = find_min_index(*a);
	if (index == 1)
		ra(a);
	else if (index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (index == 3)
	{
		rra(a);
		rra(a);
	}
	else if (index == 4)
		rra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	sort_under_six(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}
