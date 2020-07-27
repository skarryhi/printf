/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsixnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:16:20 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:16:22 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t			ft_putxnbr(unsigned int n, size_t j)
{
	if (n >= 16)
	{
		j = ft_putxnbr(n / 16, j);
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
