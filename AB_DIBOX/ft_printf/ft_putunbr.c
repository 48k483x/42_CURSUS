/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:22:30 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/14 18:16:49 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putunbr(int nbr, int *len)
{
	unsigned int	n;

	n = (unsigned int)nbr;
	if (n >= 10)
		ft_putunbr(n / 10, len);
	ft_putchar((n % 10 + '0'), len);
}
