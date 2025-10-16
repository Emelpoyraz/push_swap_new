/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epoyraz <epoyraz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:32:20 by epoyraz           #+#    #+#             */
/*   Updated: 2025/10/16 15:32:21 by epoyraz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	in_lis(int val, int *lis, int lis_len)
{
	int	i;

	i = 0;
	while (i < lis_len)
	{
		if (lis[i] == val)
			return (1);
		i++;
	}
	return (0);
}

static void	insert_from_b(t_node **a, t_node **b)
{
	t_insert_data	data;

	data.cur = *b;
	data.best_cost = 2147483647;
	data.best = NULL;
	while (data.cur)
	{
		data.target_pos = find_insert_position(*a, data.cur->value);
		data.cost_a = rotation_cost(*a, data.target_pos);
		data.cost_b = rotation_cost(*b, node_index(*b, data.cur));
		if (abs(data.cost_a) + abs(data.cost_b) < data.best_cost)
		{
			data.best_cost = abs(data.cost_a) + abs(data.cost_b);
			data.best = data.cur;
		}
		data.cur = data.cur->next;
	}
	execute_best_move(a, b, data.best);
}

static void	push_non_lis_to_b(t_push_data *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (!in_lis((*(data->a))->value, data->lis, data->lis_len))
			pb(data->a, data->b);
		else
			ra(data->a);
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
	t_push_data	push_data;
	int			size;
	int			lis_len;
	int			*lis;

	size = stack_size(*a);
	lis = find_lis(*a, size, &lis_len);
	if (!lis)
		return ;
	push_data.a = a;
	push_data.b = b;
	push_data.lis = lis;
	push_data.lis_len = lis_len;
	push_data.size = size;
	push_non_lis_to_b(&push_data);
	while (*b)
		insert_from_b(a, b);
	rotate_min_to_top(a);
	free(lis);
}
