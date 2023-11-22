/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:56:56 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/21 18:48:44 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
        ft_printf("This the first char x : %c\n and this is the second one : %c\n", 97, 98);
	ft_printf("This is my first name : %s\n and this my second name    : %s\n", a, b);
	ft_printf("This is my birhtday %d / %i, and this my birthyear %d\n and this is my age : %i\n", d,m,n*-1,age);
	ft_printf("\nAnd a new line to separe\n");
	ft_printf("This the memory adress of that : %p\n", a);
	printf("This the original one          : %p\n", a);
	printf("Original printf in u case : %u\n", -100000);
	ft_printf("This is mine to handle the u : %u\n", -100000);
	ft_printf("this the test of the percentage cspdiuxX% \n");

}
