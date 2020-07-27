/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:01:59 by skarry            #+#    #+#             */
/*   Updated: 2020/07/27 14:02:03 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t			ft_putpnbr(size_t n, size_t j)
{
	if (n >= 16)
	{
		j = ft_putpnbr(n / 16, j);
		if (n % 16 < 10)
			j = ft_putchar((n % 16) + '0', j);
		else
			j = ft_putchar((n % 16 + 87), j);
	}
	else
	{
		if (n < 10)
			j = ft_putchar(n + '0', j);
		else
			j = ft_putchar(n + 87, j);
	}
	return (j);
}
