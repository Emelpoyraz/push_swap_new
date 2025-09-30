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

static void	compute_lis(int *arr, int *dp, int *prev,
			int size, int *max_len, int *max_idx)
{
	int	i;
	int	j;

	*max_len = 1;
	*max_idx = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		if (dp[i] > *max_len)
		{
			*max_len = dp[i];
			*max_idx = i;
		}
		i++;
	}
}

static int	*reconstruct_lis(int *arr, int *prev,
			int max_len, int max_idx)
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
	int	*arr;
	int	*dp;
	int	*prev;
	int	max_len;
	int	max_idx;
	int	*lis;

	arr = flatten_stack(a, size);
	dp = malloc(sizeof(int) * size);
	prev = malloc(sizeof(int) * size);
	if (!arr || !dp || !prev)
		return (NULL);
	init_dp_arrays(dp, prev, size);
	compute_lis(arr, dp, prev, size, &max_len, &max_idx);
	*lis_len = max_len;
	lis = reconstruct_lis(arr, prev, max_len, max_idx);
	free(arr);
	free(dp);
	free(prev);
	return (lis);
}