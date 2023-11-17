/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:39:17 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/17 08:50:56 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*size_t	counter(char const *str, char split_set)
{
	size_t	i;
	size_t	w_count;

	i = 0;
	w_count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == split_set)
			i++;
		if (str[i])
		{
			w_count++;
			while (str[i] && str[i] != split_set)
				i++;
		}
	}
	return (w_count);
}

char	**initialize_indexes_str_arr(size_t *i, size_t *j, size_t *k, size_t wc)
{
	char	**str;

	*i = 0;
	*j = 0;
	*k = 0;
	str = malloc(sizeof(char **) * (wc + 1));
	if (!str)
		return (NULL);
	return (str);
}

int	lines_25_fix(char const *s, char c, size_t *i, size_t *j, char **str)
{
	size_t	len;
	size_t	k;

	len = 0;
	k = 0;
	while (s[*j + len] && s[*j + len] != c)
		len++;
	str[*i] = (char *)malloc(len + 1);
	if (!str[*i])
	{
		while (k < *i)
			free(str[(k)++]);
		free(str);
		return (-1);
	}
	ft_strlcpy(str[*i], s + (*j), len + 1);
	str[*i][len] = '\0';
	(*i)++;
	(*j) += len;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	wc;
	size_t	k;
	char	**str;

	wc = counter(s, c);
	str = initialize_indexes_str_arr(&i, &j, &k, wc);
	while (i < wc)
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && lines_25_fix(s, c, &i, &j, str) == -1)
			return  (NULL);
	}
	str[wc] = NULL;
	return (str);
}
*/
int	count_strings(char const *s, char c)
{
	int	i;
	int	str_count;

	i = 0;
	str_count = 0;
	if (s[i] == c)
		str_count--;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			str_count++;
		i++;
	}
	str_count++;
	return (str_count);
}

char	*malloc_strings(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	words = count_strings(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[i] = malloc_strings(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
