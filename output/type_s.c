/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:19:20 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:19:22 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t	type_s(va_list pu, size_t j, t_flags basket)
{
	char	*spu;

	if (!(spu = va_arg(pu, char *)))
		spu = "(null)";
	if (basket.is_left < 0)
		basket.is_left *= -1;
	if (basket.is_dot <= -1 || basket.is_dot > (int)ft_strlen(spu))
		basket.is_dot = ft_strlen(spu);
	if (basket.is_right)
		basket.is_right = basket.is_right - basket.is_dot;
	if (basket.is_left)
		basket.is_left = basket.is_left - basket.is_dot;
	while (basket.is_right-- > 0)
	{
		if (basket.is_null == ' ')
			j = ft_putchar(' ', j);
		if (basket.is_null == '0')
			j = ft_putchar('0', j);
	}
	while (basket.is_dot-- > 0)
		j = ft_putchar(*spu++, j);
	while (basket.is_left-- > 0)
		j = ft_putchar(' ', j);
	return (j);
}
