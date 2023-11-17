/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:55:38 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/07 12:48:53 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_lenght;
	size_t	indexes;

	src_lenght = ft_strlen(src);
	indexes = size - 1;
	i = 0;
	if (size == 0)
		return (src_lenght);
	while (i < indexes && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_lenght);
}
