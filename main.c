#include <stdio.h>
#include "include/push_swap.h"

int main(int argc, char **argv)
{
    t_node *a;
    t_node *b;

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

    return (free_stack(&a),free_stack(&b),0);
}
