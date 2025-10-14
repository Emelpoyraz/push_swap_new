#include "../include/push_swap.h"

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	exit_error_safe(t_node **stack, char **split)
{
	if (stack && *stack)
		free_stack(stack);
	if (split)
		free_split(split);
	exit_error();
}

t_node	*process_arg(char *arg, t_node *stack)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		exit_error_safe(&stack, NULL);
	new->value = ft_atoi(arg);
	new->next = stack;
	return (new);
}
