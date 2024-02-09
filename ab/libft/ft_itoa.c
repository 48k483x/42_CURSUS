/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 01:05:20 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/14 00:18:05 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	alloc_size(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*zero(char *tab)
{
	tab = malloc(2 * sizeof(char));
	if (!tab)
		return (NULL);
	tab[0] = '0';
	tab[1] = '\0';
	return (tab);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	len;
	char	*tab;

	nbr = n;
	tab = NULL;
	if (nbr == 0)
		return (zero(tab));
	len = alloc_size(nbr);
	tab = malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[len--] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		tab[0] = '-';
	}
	while (nbr > 0)
	{
		tab[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (tab);
}
