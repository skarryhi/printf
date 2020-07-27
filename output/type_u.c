/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:19:28 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:19:31 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void	reflags2(t_flags *basket, unsigned int ipu)
{
	if (basket->is_dot >= (int)ft_ulen(ipu))
		basket->is_dot -= ft_ulen(ipu);
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

static void	reflags(t_flags *basket, int f, unsigned int ipu)
{
	if (basket->is_dot > -1)
		basket->is_null = ' ';
	if (basket->is_dot == -1 || basket->is_dot < (int)ft_ulen(ipu))
		basket->is_dot = ft_ulen(ipu);
	if (basket->is_right)
	{
		basket->is_right = basket->is_right - basket->is_dot;
		if (!f)
			basket->is_right++;
	}
	if (basket->is_left)
	{
		basket->is_left = basket->is_left - basket->is_dot;
		if (!f)
			basket->is_left++;
	}
	reflags2(&*basket, ipu);
}

size_t		type_u(va_list pu, size_t j, t_flags basket)
{
	unsigned int	ipu;
	int				f;

	ipu = va_arg(pu, unsigned int);
	if (!ipu && !basket.is_dot)
		f = 0;
	else
		f = 1;
	reflags(&basket, f, ipu);
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
		j = ft_putunbr(ipu, j);
	while (basket.is_left-- > 0)
		j = ft_putchar(' ', j);
	return (j);
}
