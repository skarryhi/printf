/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:09:04 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:09:17 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static size_t	track(va_list pu, char c, t_flags basket, size_t j)
{
	if (c == '%')
		j = type_proc(j, basket);
	if (c == 'c')
		j = type_c(pu, j, basket);
	if (c == 's')
		j = type_s(pu, j, basket);
	if (c == 'd' || c == 'i')
		j = type_di(pu, j, basket);
	if (c == 'u')
		j = type_u(pu, j, basket);
	if (c == 'p')
		j = type_p(pu, j, basket);
	if (c == 'x' || c == 'X')
	{
		basket.x = c;
		j = type_x(pu, j, basket);
	}
	return (j);
}

static void		reflags(t_flags *basket)
{
	if (basket->is_left < 0)
		basket->is_left *= -1;
	if (basket->is_right < 0)
	{
		basket->is_left = basket->is_right;
		basket->is_left *= -1;
		basket->is_right = 0;
	}
}

size_t			check_flags(const char *str, va_list pu, size_t i, size_t *j)
{
	t_flags		basket;

	basket.is_null = ' ';
	basket.is_right = 0;
	basket.is_left = 0;
	basket.is_dot = -98765;
	while (ft_isflag(str[i]))
	{
		if (str[i] == '-' && i++)
			i = work_with_star(pu, str, i, &basket.is_left);
		if (str[i] == '0' && i++)
			basket.is_null = '0';
		if (str[i] == '.' && i++)
			i = work_with_star(pu, str, i, &basket.is_dot);
		if (ft_isdigit(str[i]) || str[i] == '*')
			i = work_with_star(pu, str, i, &basket.is_right);
	}
	reflags(&basket);
	*j = track(pu, str[i], basket, *j);
	return (i);
}
