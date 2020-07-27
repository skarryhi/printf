/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:16:08 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:16:11 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t	ft_putnbr(int n, size_t j)
{
	if (n == -2147483648)
		j = ft_putstr("-2147483648", j);
	else if (n < 0)
	{
		j = ft_putchar('-', j);
		j = ft_putnbr(-n, j);
	}
	else if (n >= 10)
	{
		j = ft_putnbr(n / 10, j);
		j = ft_putchar((n % 10) + '0', j);
	}
	else
		j = ft_putchar(n + '0', j);
	return (j);
}
