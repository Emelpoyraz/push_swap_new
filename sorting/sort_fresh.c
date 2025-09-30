#include "../include/push_swap.h"

/* ===== Helper: Find Longest Increasing Subsequence (LIS) ===== */
static int	*find_lis(t_node *a, int size, int *lis_len)
{
	int	*arr;
	int	*dp;
	int	*prev;
	int	i, j, max_len, max_idx;

	arr = malloc(sizeof(int) * size);
	dp = malloc(sizeof(int) * size);
	prev = malloc(sizeof(int) * size);
	if (!arr || !dp || !prev)
		return (NULL);
	i = 0;
	while (a) // flatten stack into array
	{
		arr[i++] = a->value;
		a = a->next;
	}
	max_len = 1;
	max_idx = 0;
	for (i = 0; i < size; i++)
	{
		dp[i] = 1;
		prev[i] = -1;
		for (j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
		if (dp[i] > max_len)
		{
			max_len = dp[i];
			max_idx = i;
		}
	}
	*lis_len = max_len;
	int *lis = malloc(sizeof(int) * max_len);
	int k = max_len - 1;
	for (i = max_idx; i >= 0; i = prev[i])
		lis[k--] = arr[i];
	free(arr);
	free(dp);
	free(prev);
	return (lis);
}

/* ===== Helper: Check if value is in LIS ===== */
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

/* ===== Choose cheapest move to insert element from B ===== */
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

/* ===== Main Sorting: LIS + greedy reinsertion ===== */
void	sort_fresh(t_node **a, t_node **b)
{
	int		size;
	int		lis_len;
	int		*lis;

	size = stack_size(*a);
	lis = find_lis(*a, size, &lis_len);
	if (!lis)
		return ;
	// push non-LIS elements to B
	int i = 0;
	while (i < size)
	{
		if (!in_lis((*a)->value, lis, lis_len))
			pb(a, b);
		else
			ra(a);
		i++;
	}
	// reinsert B into A greedily
	while (*b)
		insert_from_b(a, b);
	// rotate A so smallest value is on top
	while (find_min_index(*a) != 0)
    {
        if (find_min_index(*a) <= stack_size(*a) / 2)
            ra(a);
        else
            rra(a);
    }
	free(lis);
}
