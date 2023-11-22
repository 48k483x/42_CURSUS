/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:10:54 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/22 18:56:55 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *str);
int		ft_putchar(int x);
int		ft_putptr(uintptr_t ptr);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int n);
void	ft_puthexa(uintptr_t n, int cases);
int		ft_puthex(unsigned int n, int cases);
size_t	ft_strlen(const char *s);

#endif
