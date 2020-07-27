/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <skarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:18:54 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 13:03:00 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t	type_c(va_list pu, size_t j, t_flags basket)
{
	if (basket.is_right)
		basket.is_right = basket.is_right - 1;
	if (basket.is_left)
		basket.is_left = basket.is_left - 1;
	while (basket.is_right-- > 0)
	{
		if (basket.is_null == ' ')
			j = ft_putchar(' ', j);
		if (basket.is_null == '0')
			j = ft_putchar('0', j);
	}
	j = ft_putchar(va_arg(pu, int), j);
	while (basket.is_left-- > 0)
		j = ft_putchar(' ', j);
	return (j);
}
