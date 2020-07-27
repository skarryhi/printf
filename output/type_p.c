/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:15:12 by skarry            #+#    #+#             */
/*   Updated: 2020/07/27 14:15:16 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static size_t	output(size_t j, t_flags basket, size_t ipu, int f)
{
	while (basket.is_right-- > 0)
	{
		if (basket.is_null == '0')
			j = ft_putchar('0', j);
		else
			j = ft_putchar(' ', j);
	}
	j = ft_putstr("0x", j);
	while (basket.is_dot-- > 0)
		j = ft_putchar('0', j);
	if (f)
		j = ft_putpnbr(ipu, j);
	while (basket.is_left-- > 0)
		j = ft_putchar(' ', j);
	return (j);
}

static void		is_null(t_flags *basket, size_t ipu)
{
	if (basket->is_null == '0')
	{
		basket->is_dot += basket->is_right;
		basket->is_right = 0;
	}
	if (basket->is_null == ' ' && ipu < 0 && basket->is_dot)
	{
		basket->is_dot++;
		if (basket->is_right)
			basket->is_right--;
	}
}

static int		exist(int k, int d, int f)
{
	k = k - d;
	if (!f)
		k++;
	k -= 2;
	return (k);
}

size_t			type_p(va_list pu, size_t j, t_flags basket)
{
	size_t	ipu;
	int		f;

	ipu = va_arg(pu, size_t);
	if (!ipu && !basket.is_dot)
		f = 0;
	else
		f = 1;
	if (basket.is_dot > -1)
		basket.is_null = ' ';
	if (basket.is_dot == -1 || basket.is_dot < (int)ft_plen(ipu))
		basket.is_dot = ft_plen(ipu);
	if (basket.is_right)
		basket.is_right = exist(basket.is_right, basket.is_dot, f);
	if (basket.is_left)
		basket.is_left = exist(basket.is_left, basket.is_dot, f);
	if (basket.is_dot >= (int)ft_plen(ipu))
		basket.is_dot -= ft_plen(ipu);
	is_null(&basket, ipu);
	return (output(j, basket, ipu, f));
}
