/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:16:47 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:16:50 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t	ft_putunbr(unsigned int n, size_t j)
{
	if (n == 2147483648)
		j = ft_putstr("2147483648", j);
	else if (n >= 10)
	{
		j = ft_putunbr(n / 10, j);
		j = ft_putchar((n % 10) + '0', j);
	}
	else
		j = ft_putchar(n + '0', j);
	return (j);
}
