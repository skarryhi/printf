/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:19:39 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:19:43 by skarry           ###   ########.fr       */
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
	while (basket.is_dot-- > 0)
		j = ft_putchar('0', j);
	if (f)
	{
		if (basket.x == 'x')
			j = ft_putxnbr(ipu, j);
		if (basket.x == 'X')
			j = ft_putxbignbr(ipu, j);
	}
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
	return (k);
}

size_t			type_x(va_list pu, size_t j, t_flags basket)
{
	unsigned int	ipu;
	int				f;

	ipu = va_arg(pu, size_t);
	if (!ipu && !basket.is_dot)
		f = 0;
	else
		f = 1;
	if (basket.is_dot > -1)
		basket.is_null = ' ';
	if (basket.is_dot == -1 || basket.is_dot < (int)ft_xlen(ipu))
		basket.is_dot = ft_xlen(ipu);
	if (basket.is_right)
		basket.is_right = exist(basket.is_right, basket.is_dot, f);
	if (basket.is_left)
		basket.is_left = exist(basket.is_left, basket.is_dot, f);
	if (basket.is_dot >= (int)ft_xlen(ipu))
		basket.is_dot -= ft_xlen(ipu);
	is_null(&basket, ipu);
	return (output(j, basket, ipu, f));
}
