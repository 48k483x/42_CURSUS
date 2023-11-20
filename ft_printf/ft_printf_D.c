/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:42:43 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/20 10:00:03 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

void	ft_printf_d(const char *format, ...)
{
	va_list		args;
	long long	x;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				x = va_arg(args, long long);
				ft_putnbr(x);
			}
		}
		else
		{
			ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
}
