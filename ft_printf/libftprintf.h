/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:10:54 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/20 09:22:05 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

void	ft_putstr(char *str);
void	ft_putchar(char x);
void	ft_putnbr(int nb);
void	ft_printf_c(const char *format, ...);
void	ft_printf_s(const char *format, ...);
void	ft_printf_d(const char *format, ...);
size_t	ft_strlen(const char *s);

#endif
