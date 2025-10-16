/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epoyraz <epoyraz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:32:45 by epoyraz           #+#    #+#             */
/*   Updated: 2025/10/16 15:33:15 by epoyraz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	node_index(t_node *stack, t_node *target)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack == target)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	rotation_cost(t_node *stack, int index)
{
	int	size;

	size = stack_size(stack);
	if (index <= size / 2)
		return (index);
	else
		return (index - size);
}

int	min_index(t_node *stack)
{
	int	min;
	int	index;
	int	i;

	if (!stack)
		return (-1);
	min = stack->value;
	index = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}
