/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:49:35 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/07 15:44:10 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	m;
	size_t			i;

	p = (unsigned char *)s;
	m = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == m)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
