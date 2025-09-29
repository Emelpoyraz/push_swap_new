#include "../include/push_swap.h"

static int *to_array(t_node *stack, int size)
{
    int *arr;
    int i;

    arr = malloc(sizeof(int) * size);
    if(!arr)
        exit_error();
    i = 0;
    while (stack)
    {
        arr[i++] = stack->value;
        stack = stack->next;
    }
    return(arr);
}

static void sort_array(int *arr, int size)
{
    int tmp;
    int i;
    int j;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}
static int get_index(int *arr, int size, int value)
{
    int i;
    
    i = 0;
    while (i < size)
    {
        if(arr[i] == value)
            return(i);
        i++;    
    }
    return (0);
}
void normalize_stack(t_node *stack)
{
    int *sorted;
    int size;
    t_node *tmp;

    size = stack_size(stack);
    sorted = to_array(stack, size);
    sort_array(sorted, size);
    tmp = stack;
    while (tmp)
    {
        tmp->value = get_index(sorted, size, tmp->value);
        tmp = tmp->next;
    }
    free(sorted);
}