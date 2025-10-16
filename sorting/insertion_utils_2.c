#include "../include/push_swap.h"

/* ===== Get index of a node in stack ===== */
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

/* ===== Cost to rotate stack until index is at top ===== */
int	rotation_cost(t_node *stack, int index)
{
	int	size;

	size = stack_size(stack);
	if (index <= size / 2)
		return (index); // positive = rotate
	else
		return (index - size); // negative = reverse rotate
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
