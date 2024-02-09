/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:05:46 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/14 18:16:36 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	to_hex(unsigned long add, char *format, int *len)
{
	if (add >= 16)
		to_hex(add / 16, format, len);
	ft_putchar(format[add % 16], len);
}

void	ft_putadd(void *p, int *len)
{
	unsigned long	add;

	add = (unsigned long)p;
	if (add == 0)
		ft_putstr("(nil)", len);
	else
	{
		ft_putstr("0x", len);
		to_hex(add, "0123456789abcdef", len);
	}
}
