/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:30:07 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/14 18:16:28 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_format(va_list args, const char format, int *len)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (format == 'u')
		ft_putunbr(va_arg(args, unsigned int), len);
	else if (format == 'x')
		ft_puthex(va_arg(args, int), "0123456789abcdef", len);
	else if (format == 'X')
		ft_puthex(va_arg(args, int), "0123456789ABCDEF", len);
	else if (format == 'p')
		ft_putadd(va_arg(args, void *), len);
	else if (format == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_format(args, str[i], &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
