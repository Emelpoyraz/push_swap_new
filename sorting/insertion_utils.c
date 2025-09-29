#include "../include/push_swap.h"

/* ===== Get index of a node in stack ===== */
int	node_index(t_node *stack, t_node *target)
{
	int i = 0;
	while (stack)
	{
		if (stack == target)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

/* ===== Find position to insert value in sorted stack A ===== */
int	find_insert_position(t_node *a, int value)
{
	t_node	*cur = a;
	int		pos = 0;

	if (!a)
		return (0);

	int min_pos = find_min_index(a);
	int min_val = a->value;
	int max_val = a->value;
	while (cur)
	{
		if (cur->value < min_val) min_val = cur->value;
		if (cur->value > max_val) max_val = cur->value;
		cur = cur->next;
	}
	if (value < min_val || value > max_val)
		return (min_pos);

	cur = a;
	while (cur->next)
	{
		if (cur->value < value && value < cur->next->value)
			return (pos + 1);
		cur = cur->next;
		pos++;
	}
	return (0);
}

/* ===== Cost to rotate stack until index is at top ===== */
int	rotation_cost(t_node *stack, int index)
{
	int size = stack_size(stack);
	if (index <= size / 2)
		return (index);        // positive = rotate
	else
		return (index - size); // negative = reverse rotate
}

/* ===== Execute the best move to insert chosen node from B → A ===== */
void	execute_best_move(t_node **a, t_node **b, t_node *target)
{
	int pos_a, pos_b;
	int cost_a, cost_b;

	pos_a = find_insert_position(*a, target->value);
	pos_b = node_index(*b, target);

	cost_a = rotation_cost(*a, pos_a);
	cost_b = rotation_cost(*b, pos_b);

	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}

	while (cost_a > 0) { ra(a); cost_a--; }
	while (cost_a < 0) { rra(a); cost_a++; }
	while (cost_b > 0) { rb(b); cost_b--; }
	while (cost_b < 0) { rrb(b); cost_b++; }

	pa(a, b);
}
int min_index(t_node *stack)
{
    int min;
    int index;
    int i;

    if(!stack)
        return(-1);
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
