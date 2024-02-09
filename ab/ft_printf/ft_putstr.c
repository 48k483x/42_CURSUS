/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:04:38 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/14 18:16:47 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	if (!str)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		while (*str)
		{
			ft_putchar(*str, len);
			str++;
		}
	}
}
