/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_C.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:44:54 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/20 08:46:47 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_c(const char *format, ...)
{
	int			x;
	va_list		args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				x = va_arg(args, int);
				ft_putchar(x);
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
