/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epoyraz <epoyraz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:52:13 by epoyraz           #+#    #+#             */
/*   Updated: 2025/06/22 11:03:03 by epoyraz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_calloc(size_t count, size_t size)
{
	size_t			total;
	size_t			i;
	unsigned char	*ptr;	

	total = count * size;
	ptr = malloc(total);
	i = 0;
	if (!ptr)
		return (NULL);
	while (i < total)
		ptr[i++] = 0;
	return (ptr);
}
