/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubie <yubie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:10:07 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/17 15:14:16 by yubie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	if (!*s || !s)
		return (0);
	return (1 + ft_strlen_gnl(++s));
}

char	*ft_strdup_gnl(char *s)
{
	char	*dup;
	int		i;

	dup = malloc((ft_strlen_gnl(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	str = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s1);
	str[j + i] = '\0';
	return (str);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen_gnl(s);
	while (i + start < slen && i < len)
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	slen = 0;
	while (i > 0)
	{
		str[slen++] = s[start++];
		i--;
	}
	str[slen] = '\0';
	return (str);
}

int	ft_strnl_gnl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
