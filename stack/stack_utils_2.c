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
    return(size);
}
int find_min_index(t_node *stack)
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

void free_stack(t_node **stack)
{
    t_node *temp;

    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}