/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 11:16:04 by skarry            #+#    #+#             */
/*   Updated: 2020/07/20 11:16:08 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t	type_proc(size_t j, t_flags basket)
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
	j = ft_putchar('%', j);
	while (basket.is_left-- > 0)
		j = ft_putchar(' ', j);
	return (j);
}
