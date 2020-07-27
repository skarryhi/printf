/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbignbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:15:45 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:15:48 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t	ft_putxbignbr(unsigned int n, size_t j)
{
	if (n >= 16)
	{
		j = ft_putxbignbr(n / 16, j);
		if (n % 16 < 10)
			j = ft_putchar((n % 16) + '0', j);
		else
			j = ft_putchar((n % 16 + 55), j);
	}
	else
	{
		if (n < 10)
			j = ft_putchar(n + '0', j);
		else
			j = ft_putchar(n + 55, j);
	}
	return (j);
}
