#include "../include/push_swap.h"

int	get_max_position(t_node *stack)
{
	int		pos;
	int		max_pos;
	int		max;
	t_node	*temp;

	pos = 0;
	max_pos = 0;
	max = stack->index;
	temp = stack;
	while (temp)
	{
		if (temp->index > max)
		{
			max = temp->index;
			max_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	return (max_pos);
}

void	rotate_smart(t_node **b)
{
	int	pos;
	int	size;

	pos = get_max_position(*b);
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos--)
			rb(b);
	}
	else
	{
		while (pos++ < size)
			rrb(b);
	}
}

void	pa_smart(t_node **a, t_node **b)
{
	if (!*b)
		return ;
	rotate_smart(b);
	pa(a, b);
}
