/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epoyraz <epoyraz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:58:01 by epoyraz           #+#    #+#             */
/*   Updated: 2025/10/16 14:01:02 by epoyraz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int stack_size(t_node *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}
int find_min_index(t_node *stack)
{
    int min;
    int index;
    int i;

    if(!stack)
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

void exit_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}
