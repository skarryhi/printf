/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:13:14 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:13:17 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_flags
{
	char		is_null;
	int			is_right;
	int			is_left;
	int			is_dot;
	char		x;
}				t_flags;

int				ft_printf(const char *str, ...);
size_t			ft_putchar(char c, size_t j);
size_t			work_with_star(va_list pu, const char *str,\
				size_t i, int *star);
int				ft_isdigit(int c);
size_t			check_flags(const char *str, va_list pu, size_t i, size_t *j);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isflag(int c);
size_t			ft_xlen(unsigned int n);
size_t			ft_plen(size_t n);
size_t			ft_ulen(unsigned int n);
size_t			ft_putstr(char *s, size_t j);
size_t			ft_putnbr(int n, size_t j);
size_t			ft_putxnbr(unsigned int n, size_t j);
size_t			ft_putpnbr(size_t n, size_t j);
size_t			ft_intlen(int n);
size_t			ft_putxbignbr(unsigned int n, size_t j);
size_t			ft_putunbr(unsigned int n, size_t j);
size_t			type_proc(size_t j, t_flags basket);
size_t			type_c(va_list pu, size_t j, t_flags basket);
size_t			ft_strlen(const char *str);
size_t			type_s(va_list pu, size_t j, t_flags basket);
size_t			type_di(va_list pu, size_t j, t_flags basket);
size_t			type_u(va_list pu, size_t j, t_flags basket);
size_t			type_x(va_list pu, size_t j, t_flags basket);
size_t			type_p(va_list pu, size_t j, t_flags basket);

#endif
