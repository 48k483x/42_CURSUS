/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:41:27 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/22 12:12:53 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}	
	else
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
}
