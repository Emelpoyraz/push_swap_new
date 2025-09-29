#include "../include/push_swap.h"

static long ft_atol(const char *str)
{
    int sign;
    long result;

    sign = 1;
    result = 0;
    while(*str ==' ' || (*str >= 9 && *str <=13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if(*str == '-')
            sign *= -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return ( result * sign);
}
int is_valid_number(char *str)
{
    int i;

    i = 0;
    if(!str[0])
        return (0);
    if(str[0] == '-' || str[0] == '+')
        i++;
    if(!str[0])
        return (0);
    while (str[i])
    {
        if(str[i] < '0' || str[i] > '9')
            return (0);    
        i++;
    }
    return (1);
}

int is_duplicate(t_node *stack, int value)
{
    while (stack)
    {
        if(stack->value == value)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void exit_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*stack;
	t_node	*new;
	long	num;
	int		i;

	stack = NULL;
	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_number(argv[i]))
			exit_error();
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX || is_duplicate(stack, (int)num))
			exit_error();
		new = malloc(sizeof(t_node));
		if (!new)
			exit_error();
		new->value = (int)num;
		new->next = stack;
		stack = new;
		i--;
	}
	return (stack);
}
