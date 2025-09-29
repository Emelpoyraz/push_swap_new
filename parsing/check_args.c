#include "../include/push_swap.h"

t_node *process_arg(char *arg, t_node *stack)
{
    long num;
    t_node *new;

    if(!is_valid_number(arg))
        exit_error();
    num = ft_atol(arg);
    if(num < INT_MIN || num > INT_MAX || is_duplicate(stack, (int)num))
        exit_error();
    new = malloc(sizeof(t_node));
    if(!new)
        exit_error();
    new->value = (int)num;
    new->next = stack;
    return (new);
}
