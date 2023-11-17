/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:27:34 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/07 12:10:12 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	lenght;

	lenght = ft_strlen((char *)s) + 1;
	dup = malloc(sizeof(char) * lenght);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, lenght);
	return (dup);
}
