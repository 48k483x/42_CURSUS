/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkabex <abkabex@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 04:36:19 by achahrou          #+#    #+#             */
/*   Updated: 2024/02/15 02:17:17 by abkabex          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


int	ft_strlen(char *n)
{
    int i;
	int length;

	i = 0;
	length = 0;
    while (n[i] == '0') 
        i++;
    while (n[i] != '\0')
	{
        if (ft_isdigit(n[i]))
            length++;
        i++;
	}
	return (length);
}

bool	length_check(char **n)
{
	int i;
	int length;

	i = 0;
	printf("n[i] = %s\n", n[i]);
	printf("n[i] = %s\n", n[i]);
	while (n[i])
	{
		length = ft_strlen(n[i]);
		if ((length == 10 && ft_atol(n[i]) > 2147483647LL) ||
			 (length == 10 && ft_atol(n[i]) < -2147483648LL))
			return (false);
		if (length > 10)
			return (false);
		i++;
	}
	return (true);
}


long long	ft_atol(char *nptr)
{
	long long	i;
	long long	sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
	if (num * sign > INT_MAX || num * sign < INT_MIN)
		exit_with_message("Error\n");
	return (num * sign);
}
