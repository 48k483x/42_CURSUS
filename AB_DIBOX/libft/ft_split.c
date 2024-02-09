/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:35:53 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/20 00:08:16 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_sep(char a, char c)
{
	return (a == c);
}

static size_t	word_count(const char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_sep(str[i], c) && (is_sep(str[i + 1], c) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*word_alloc(const char *str, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (str[i] && !is_sep(str[i], c))
		i++;
	word = malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i] && !is_sep(str[i], c))
	{
		word[i] = ((char *)str)[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	*free_all(char **sp)
{
	size_t	i;

	i = 0;
	while (sp[i])
	{
		free(sp[i]);
		i++;
	}
	free(sp);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**sp;

	if (!s)
		return (NULL);
	sp = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!sp || word_count(s, c) == 0)
		return (free(sp), (NULL));
	i = 0;
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s && !is_sep(*s, c))
		{
			sp[i] = word_alloc(s, c);
			if (!sp[i])
				return (free_all(sp));
			i++;
			while (*s && !is_sep(*s, c))
				s++;
		}
	}
	sp[i] = NULL;
	return (sp);
}
