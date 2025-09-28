/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epoyraz <epoyraz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:55:34 by epoyraz           #+#    #+#             */
/*   Updated: 2025/06/22 15:25:58 by epoyraz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strchr(const char *s, int c)
{
	unsigned char uc;

	uc = (unsigned char)c;	
	while (*s)
	{
		if((unsigned char)*s == uc)
			return(char *)s;
		s++;
	}
	if(uc == '\0')
		return (char *)s;
	return (NULL);
	
}
