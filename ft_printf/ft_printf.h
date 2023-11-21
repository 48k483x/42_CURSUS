/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:10:54 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/21 18:33:40 by achahrou         ###   ########.fr       */
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
void	ft_putstr(char *str);
void	ft_putchar(char x);
void	ft_putptr(void *ptr);
void	ft_putnbr(int nb);
void	ft_putunbr(int n);
void	ft_puthexa(uintptr_t n, int cases);
size_t	ft_strlen(const char *s);

#endif
