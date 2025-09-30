#include "../include/push_swap.h"

long ft_atol(const char *str)
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
    if (!str[0])
        return (0);
    if ((str[0] == '-' || str[0] == '+') && !str[1])
        return (0);
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
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
int validate_number(char *str, t_node *stack, char **split)
{
    long num;

    if (!is_valid_number(str))
        exit_error_safe(&stack, split);
    num = ft_atol(str);
    if (num < INT_MIN || num > INT_MAX || is_duplicate(stack, (int)num))
        exit_error_safe(&stack, split);
    return ((int)num);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*stack;
	char	**split;
    int num;
	int i;
	int j;

	stack = NULL;
	i = argc - 1;
	while (i > 0)
	{
        split = ft_split(argv[i], ' ');
        if(!split || !split[0])
            exit_error_safe(&stack, split);
        j = 0;
        while (split[j])
        {
            num = validate_number(split[j],stack,split);
            (void)num;
            stack = process_arg(split[j], stack);
            j++;
        }
        free_split(split);
        i--;
	}
	return (stack);
}
