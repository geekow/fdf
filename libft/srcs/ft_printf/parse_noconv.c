/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_noconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:27:52 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/30 19:34:26 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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

int			parse_noconv(t_info *info, char c)
{
	if (!flag_zero(info->flag_minus, info->flag_zero, info->min_size))
		return (-1);
	if (!flag_space(info->flag_minus, info->flag_zero, info->min_size))
		return (-1);
	if (!addchar(c, 1))
		return (-1);
	if (info->flag_minus && (info->min_size > 1))
		if (!flag_space(0, 0, info->min_size))
			return (-1);
	return (1);
}
