/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:05:33 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:06:01 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/ft_printf.h"

int		ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	j;
	va_list	pu;

	i = 0;
	j = 0;
	va_start(pu, str);
	while (str[i])
	{
		if (str[i] == '%' && ++i)
			i = check_flags(str, pu, i, &j);
		else
			j = ft_putchar(str[i], j);
		if (!str[i])
			break ;
		i++;
	}
	va_end(pu);
	return (j);
}
