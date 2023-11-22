/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:21:21 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/22 20:17:55 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	al_fa7ce(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'p')
		count += ft_putptr(va_arg(args, uintptr_t));
	else if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (format == '%')
		count += ft_putchar('%');
	else if (format == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_puthex(va_arg(args, uintmax_t), 0);
	else if (format == 'X')
		count += ft_puthex(va_arg(args, uintmax_t), 1);
	return (count);
}

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
			else
				count += al_fa7ce(args, *format);
		}
		else
		{
			ft_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
