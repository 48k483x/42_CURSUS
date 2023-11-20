/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_S.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:03:27 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/20 08:47:02 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

void	ft_printf_s(const char *format, ...)
{
	va_list	args;
	char	*x;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				x = va_arg(args, char *);
				ft_putstr(x);
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
