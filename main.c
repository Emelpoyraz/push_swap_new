
#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	b = NULL;
	normalize_stack(a);
	sort_all(&a,&b);
	free_stack(&a);
	return (0);
}
