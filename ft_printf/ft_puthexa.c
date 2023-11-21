/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:55:17 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/21 18:26:10 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(uintptr_t n, int cases)
{
	int	remainder;

	remainder = n % 16;
	if (n == 0)
	{
		ft_putchar(48);
		return ;
	}
	if (n / 16 != 0)
		ft_puthexa(n / 16, cases);
	if (remainder < 10)
		ft_putchar(48 + remainder);
	else if (cases == 0)
		ft_putchar('a' + remainder - 10);
	else
		ft_putchar('A' + remainder - 10);
}
