#include "../include/push_swap.h"
/////2ND FUNCTION//////
static int	in_lis(int val, int *lis, int lis_len)
{
	int i = 0;
	while (i < lis_len)
	{
		if (lis[i] == val)
			return (1);
		i++;
	}
	return (0);
}
/////3RD FUNCTION//////////
static void	insert_from_b(t_node **a, t_node **b)
{
	t_node *cur = *b;
	int		target_pos;
	int		cost_a, cost_b, best_cost = 2147483647;
	t_node *best = NULL;

	while (cur)
	{
		target_pos = find_insert_position(*a, cur->value);
		cost_a = rotation_cost(*a, target_pos);
		cost_b = rotation_cost(*b, node_index(*b, cur));
		if (abs(cost_a) + abs(cost_b) < best_cost)
		{
			best_cost = abs(cost_a) + abs(cost_b);
			best = cur;
		}
		cur = cur->next;
	}
	execute_best_move(a, b, best);
}
/////4TH   FUNCTION
static void	push_non_lis_to_b(t_node **a, t_node **b,
			int *lis, int lis_len, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!in_lis((*a)->value, lis, lis_len))
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

static void	rotate_min_to_top(t_node **a)
{
	int	min_index;
	int	half;

	min_index = find_min_index(*a);
	half = stack_size(*a) / 2;
	while (find_min_index(*a) != 0)
	{
		if (min_index <= half)
			ra(a);
		else
			rra(a);
		min_index = find_min_index(*a);
	}
}

void	sort_fresh(t_node **a, t_node **b)
{
	int	size;
	int	lis_len;
	int	*lis;

	size = stack_size(*a);
	lis = find_lis(*a, size, &lis_len);
	if (!lis)
		return ;
	push_non_lis_to_b(a, b, lis, lis_len, size);
	while (*b)
		insert_from_b(a, b);
	rotate_min_to_top(a);
	free(lis);
}
