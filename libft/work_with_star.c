/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:12:02 by skarry            #+#    #+#             */
/*   Updated: 2020/07/12 12:12:05 by skarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

size_t	work_with_star(va_list pu, const char *str, size_t i, int *star)
{
	*star = 0;
	if (str[i] == '*' && i++)
		*star = va_arg(pu, int);
	if (ft_isdigit(str[i]))
	{
		*star = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}
