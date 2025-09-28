/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epoyraz <epoyraz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:29:55 by epoyraz           #+#    #+#             */
/*   Updated: 2025/06/22 11:34:59 by epoyraz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (i-- > 0)
		res[i] = f(i, s[i]);
	return (res);
}
