/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epoyraz <epoyraz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:36:15 by epoyraz           #+#    #+#             */
/*   Updated: 2025/10/16 14:36:16 by epoyraz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	b = NULL;
	normalize_stack(a);
	if (stack_size(a) <= 5)
		sort_under_six(&a, &b);
	else
		sort_fresh(&a, &b);
	return (free_stack(&a), free_stack(&b), 0);
}
