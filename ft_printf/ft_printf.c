/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:21:21 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/21 18:35:36 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			else if (*format == 'p')
				ft_putptr(va_arg(args, void *));
			else if (*format == 'c')
				ft_putchar(va_arg(args, int));
			else if (*format == 's')
				ft_putstr(va_arg(args, char *));
			else if (*format == 'i' || *format == 'd')
				ft_putnbr(va_arg(args, int));
			else if (*format == '%')
				ft_putchar('%');
			else if (*format == 'u')
				ft_putunbr(va_arg(args, int));
		}
		else
		{
			ft_putchar(*format);
		}
		format++;
		count++;
	}
	va_end(args);
	return (count);
}
