/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epoyraz <epoyraz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:53:17 by epoyraz           #+#    #+#             */
/*   Updated: 2025/10/16 13:53:32 by epoyraz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol_checked(const char *str, t_node **stack, char **split)
{
	long	result;
	int		sign;
	int		digit;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if ((result > (LONG_MAX - digit) / 10) || (result < (LONG_MIN + digit)
				/ 10))
			exit_error_safe(stack, split);
		result = result * 10 + (digit * sign);
		str++;
	}
	return (result);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	if ((str[0] == '-' || str[0] == '+') && !str[1])
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	validate_number(char *str, t_node *stack, char **split)
{
	long	num;

	if (!is_valid_number(str))
		exit_error_safe(&stack, split);
	num = ft_atol_checked(str, &stack, split);
	if (num < INT_MIN || num > INT_MAX || is_duplicate(stack, (int)num))
		exit_error_safe(&stack, split);
	return ((int)num);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*stack;
	char	**split;
	int		num;
	int		i;
	int		j;

	stack = NULL;
	i = argc - 1;
	while (i > 0)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			exit_error_safe(&stack, split);
		j = 0;
		while (split[j])
		{
			num = validate_number(split[j], stack, split);
			(void)num;
			stack = process_arg(split[j], stack);
			j++;
		}
		free_split(split);
		i--;
	}
	return (stack);
}
