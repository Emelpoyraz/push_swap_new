/*#include "../include/push_swap.h"

static int get_min_position(t_node *stack)
{
    int min;
    int pos;
    int i;
    t_node *tmp;

    if(!stack)
        return(-1);
    min = stack->value;
    pos = 0;
    i = 0;
    tmp = stack;
    while (tmp)
    {
        if (tmp->value < min)
        {
            min = tmp->value;
            pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    return(pos);
}

static void rotate_to_top(t_node **stack, int pos, int size, char stack_name)
{
    if (pos <= size/2)
    {
        while (pos-- > 0)
        {
            if(stack_name == 'a')
                ra(stack);
            else
                rb(stack);
        }
    }
    else
    {
        while(pos++ < size)
        {
            if(stack_name == 'a')
                rra(stack);
            else
                rrb(stack);
        }
    }
}
void    sort_fresh(t_node **a, t_node **b)
{
    int pos_min;
    int pos_max;
    int size;

    while (*a)
    {
        size = stack_size(*a);
        pos_min = get_min_position(*a);
        pos_max = get_max_position(*a);

        if(pos_min <= size - pos_max - 1)
        {
            rotate_to_top(a, pos_min, size, 'a');
            pb(a, b);
        }
        else
        {
            rotate_to_top(a, pos_max, size, 'a');
            pb(a,b);
        }
    }
    while(*b)
        pa_smart(a,b);
}
        */