#include "../include/push_swap.h"

static void	find_min_max(t_node *a, int *min_val, int *max_val)
{
	t_node	*cur;

	*min_val = a->value;
	*max_val = a->value;
	cur = a;
	while (cur)
	{
		if (cur->value < *min_val)
			*min_val = cur->value;
		if (cur->value > *max_val)
			*max_val = cur->value;
		cur = cur->next;
	}
}

static int	find_between_position(t_node *a, int value)
{
	t_node	*cur;
	int		pos;

	cur = a;
	pos = 0;
	while (cur->next)
	{
		if (cur->value < value && value < cur->next->value)
			return (pos + 1);
		cur = cur->next;
		pos++;
	}
	return (0);
}

int	find_insert_position(t_node *a, int value)
{
	int	min_pos;
	int	min_val;
	int	max_val;

	if (!a)
		return (0);
	min_pos = find_min_index(a);
	find_min_max(a, &min_val, &max_val);
	if (value < min_val || value > max_val)
		return (min_pos);
	return (find_between_position(a, value));
}
