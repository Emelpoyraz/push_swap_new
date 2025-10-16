#include "../include/push_swap.h"

static int	*flatten_stack(t_node *a, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i] = a->value;
		a = a->next;
		i++;
	}
	return (arr);
}

static void	init_dp_arrays(int *dp, int *prev, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dp[i] = 1;
		prev[i] = -1;
		i++;
	}
}

static void	compute_lis(t_lis_data *data)
{
	int	i;
	int	j;

	data->max_len = 1;
	data->max_idx = 0;
	i = 0;
	while (i < data->size)
	{
		j = 0;
		while (j < i)
		{
			if (data->arr[j] < data->arr[i] && data->dp[j] + 1 > data->dp[i])
			{
				data->dp[i] = data->dp[j] + 1;
				data->prev[i] = j;
			}
			j++;
		}
		if (data->dp[i] > data->max_len)
		{
			data->max_len = data->dp[i];
			data->max_idx = i;
		}
		i++;
	}
}

static int	*reconstruct_lis(int *arr, int *prev, int max_len, int max_idx)
{
	int	*lis;
	int	k;
	int	i;

	lis = malloc(sizeof(int) * max_len);
	if (!lis)
		return (NULL);
	k = max_len - 1;
	i = max_idx;
	while (i >= 0)
	{
		lis[k] = arr[i];
		k--;
		i = prev[i];
	}
	return (lis);
}

int	*find_lis(t_node *a, int size, int *lis_len)
{
	t_lis_data	data;
	int			*lis;

	data.arr = flatten_stack(a, size);
	data.dp = malloc(sizeof(int) * size);
	data.prev = malloc(sizeof(int) * size);
	data.size = size;
	if (!data.arr || !data.dp || !data.prev)
		return (NULL);
	init_dp_arrays(data.dp, data.prev, size);
	compute_lis(&data);
	*lis_len = data.max_len;
	lis = reconstruct_lis(data.arr, data.prev, data.max_len, data.max_idx);
	free(data.arr);
	free(data.dp);
	free(data.prev);
	return (lis);
}
