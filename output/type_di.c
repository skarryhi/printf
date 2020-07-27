/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:19:01 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:19:04 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static size_t	output2(size_t j, t_flags basket, int f, int ipu)
{
	if (f == 7)
	{
		if (ipu < 0)
			j = ft_putstr("-2147483648", j);
		else
			j = ft_putstr("2147483648", j);
	}
	while (basket.is_left-- > 0)
		j = ft_putchar(' ', j);
	return (j);
}

static void		reflags(t_flags *basket, int f, unsigned int ipu)
{
	if (basket->is_left < 0)
		basket->is_left *= -1;
	if (basket->is_dot > -1)
		basket->is_null = ' ';
	if (basket->is_dot == -1 || basket->is_dot < (int)ft_intlen(ipu))
		basket->is_dot = ft_intlen(ipu);
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
	if (basket->is_dot >= (int)ft_intlen(ipu))
		basket->is_dot -= ft_intlen(ipu);
}

static size_t	output(size_t j, t_flags basket, int ipu, int f)
{
	if (ipu < 0 && basket.is_null == '0')
	{
		ipu *= -1;
		j = ft_putchar('-', j);
	}
	while (basket.is_right-- > 0)
	{
		if (basket.is_null == '0')
			j = ft_putchar('0', j);
		else
			j = ft_putchar(' ', j);
	}
	if (ipu < 0 && basket.is_dot)
	{
		ipu *= -1;
		j = ft_putchar('-', j);
	}
	while (basket.is_dot-- > 0)
		j = ft_putchar('0', j);
	if (f == 1 || f == 9)
		j = ft_putnbr(ipu, j);
	return (output2(j, basket, f, ipu));
}

size_t			type_di(va_list pu, size_t j, t_flags basket)
{
	int		ipu;
	int		f;

	ipu = va_arg(pu, int);
	if (ipu == -2147483648 && ipu++)
		f = 7;
	else if ((int)ft_intlen(ipu) == basket.is_dot && ipu <= -1)
		f = 9;
	else if (!ipu && !basket.is_dot)
		f = 0;
	else
		f = 1;
	reflags(&basket, f, ipu);
	if ((ipu < 0 && basket.is_dot) || f == 9)
	{
		basket.is_dot++;
		if (basket.is_right)
			basket.is_right--;
		if (basket.is_left)
			basket.is_left--;
	}
	return (output(j, basket, ipu, f));
}
