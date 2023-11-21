/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:28:18 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/21 18:27:53 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnr(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	if (n > 9)
	{
		ft_putnr(n / 10);
		ft_putchar((n % 10) + 48);
	}
}

void	ft_putunbr(int n)
{
	unsigned int	uint_max;

	uint_max = UINT_MAX;
	if (n < 0)
		ft_putnr(uint_max - (unsigned int)(-n) + 1);
	else
		ft_putnr((unsigned int)n);
}
