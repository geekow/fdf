/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 06:19:00 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/29 16:40:18 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_zero(char flag_minus, char flag_zero, int min_size)
{
	if (!flag_minus && flag_zero && ((min_size - 1) > 0))
		return (addchar('0', min_size - 1));
	return (1);
}

static int	flag_space(char flag_minus, char flag_zero, int min_size)
{
	if (!flag_minus && !flag_zero && ((min_size - 1) > 0))
		return (addchar(' ', min_size - 1));
	return (1);
}

int			parse_percent(t_info *info, va_list args)
{
	(void)args;
	if (!flag_zero(info->flag_minus, info->flag_zero, info->min_size))
		return (-1);
	if (!flag_space(info->flag_minus, info->flag_zero, info->min_size))
		return (-1);
	if (!addchar('%', 1))
		return (-1);
	if (info->flag_minus && (info->min_size > 1))
		if (!flag_space(0, 0, info->min_size))
			return (-1);
	return (1);
}
