#include "push_swap.h"

t_node *new_node(int value)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if(!node)
        exit_error();
    node->value = value;
    node->next = NULL;
    return(node);
}

void    push_front(t_node **stack, t_node *new)
{
    if(!stack || !new)
        return;
    new->next = *stack;
    *stack = new;
}
void push_back(t_node **stack, t_node *new)
{
    t_node *last;

    if(!stack || !new)
        return;
    if(!*stack)
    {
        *stack = new;
        return;
    }
    last = *stack;
    while(last->next)
        last = last->next;
    last->next = new;
}
t_node *pop_front(t_node **stack)
{
    t_node *top;

    if(!stack || !*stack)
        return (NULL);
    top = *stack;
    *stack = (*stack)->next;
    top->next = NULL;
    return(top);
}

t_node *last_node(t_node *stack)
{
    if(!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return(stack);
}