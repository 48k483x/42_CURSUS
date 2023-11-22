/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:57:06 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/22 18:11:12 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_ptr(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_putptr(uintptr_t ptr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	if (ptr == 0)
		count += ft_putchar(48);
	else
	{
		count += len_ptr(ptr);
		ft_puthexa(ptr, 0);
	}
	return (count);
}
