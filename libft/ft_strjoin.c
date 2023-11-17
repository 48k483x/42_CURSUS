/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkabex <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:49:16 by abkabex           #+#    #+#             */
/*   Updated: 2023/11/05 16:53:34 by abkabex          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	lenght_total;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	lenght_total = ft_strlen(s1) + ft_strlen(s2);
	concat = malloc(sizeof(char) * lenght_total + 1);
	if (!concat)
		return (NULL);
	while (s1[i])
		concat[j++] = s1[i++];
	i = 0;
	while (s2[i])
		concat[j++] = s2[i++];
	concat[j] = '\0';
	return (concat);
}
