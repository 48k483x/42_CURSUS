/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:55:17 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/22 18:56:27 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_puthexa(uintptr_t n, int cases)
{
	if (n == 0)
	{
		ft_putchar(48);
		return ;
	}
	if (n / 16 != 0)
		ft_puthexa(n / 16, cases);
	if (n % 16 < 10)
		ft_putchar(48 + (n % 16));
	else if (cases == 0)
		ft_putchar('a' + ((n % 16) - 10));
	else
		ft_putchar('A' + ((n % 16) - 10));
}

int	ft_puthex(unsigned int n, int cases)
{
	if (n == 0)
		return (ft_putchar(48));
	else
		ft_puthexa(n, cases);
	return (hex_len(n));
}
