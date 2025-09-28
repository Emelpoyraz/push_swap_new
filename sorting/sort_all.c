#include "../push_swap.h"

void sort_all(t_node **a, t_node **b)
{
    int size;

    size = stack_size(*a);
    if(size <= 5)
        sort_under_six(a,b);
    else if(size <= 100)
        sort_small_medium_stack(a,b);
    else
        sort_large_huge_stack(a,b);
}