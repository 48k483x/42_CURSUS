/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:56:56 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/20 09:57:58 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main ()
{
        //char x = 'a';
        //char y = 'b';
	char	*a = "Abdurrahman";
	char	*b = "Chahrour";
	int	n = -2004;
	int	d = 9;
	int	m = 5;
	int	age = 19;
        ft_printf_c("This the first char x : %c\n and this is the second one : %c\n", 97, 98);
	ft_printf_s("This is my first name : %s\n and this my second name    : %s\n", a, b);
	ft_printf_d("This is my birhtday %d / %i, and this my birthyear %d\n and this is my age : %i", d,m,n*-1,age);
	ft_printf_c("\n And a new line to separe \n");

}
