/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:43:45 by jjacobi           #+#    #+#             */
/*   Updated: 2017/02/01 14:56:15 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	get_data(char modifs[2], va_list args)
{
	if (modifs[0] == 'l' && modifs[1] == '\0')
		return ((long)va_arg(args, unsigned long));
	else
		return ((long)va_arg(args, unsigned long));
}

static int			treatment_without_zero_begining(t_info *info, int *special,
											char **str)
{
	if (info->min_size > (*special + (int)ft_strlen(*str))
		&& !info->flag_zero)
	{
		if (-1 == addchar(' ', info->min_size - *special - ft_strlen(*str) -
					(info->flag_metadata * 2)))
			return (-1);
		if (info->flag_metadata)
			addchars("0x", 2);
	}
	else if (info->min_size > (*special + (int)ft_strlen(*str))
			&& info->flag_zero)
	{
		if (info->flag_metadata)
			if (-1 == addchars("0x", 2))
				return (-1);
		if (-1 == addchar('0', info->min_size - *special - ft_strlen(*str) -
					(info->flag_metadata * 2)))
			return (-1);
	}
	else if (info->flag_metadata)
		if (-1 == addchars("0x", 2))
			return (-1);
	return (1);
}

static int			trt_one(t_info *info, char *str,
											int *size)
{
	if ((int)ft_strlen(str) < info->precision)
		size[0] = info->precision;
	else
		size[0] = ft_strlen(str);
	if (size[0] < info->min_size && !info->flag_minus)
		if (!addchar(' ', info->min_size - size[0] - size[1] -
					(info->flag_metadata * 2)))
			return (-1);
	return (1);
}

static int			trt_two(t_info *info, unsigned long long d,
													char **str, int *size)
{
	if (info->flag_metadata)
		addchars("0x", 2);
	if (info->precision >= 0)
	{
		if (-1 == addchar('0', size[0] - ft_strlen(*str)))
			return (-1);
		if (!(d == 0 && info->precision == 0) &&
				-1 == addchars(*str, ft_strlen(*str)))
			return (-1);
	}
	else if (info->precision != 0 || d != 0)
		if (-1 == addchars(*str, ft_strlen(*str)))
			return (-1);
	if (info->flag_minus && (size[0] + size[1]) < info->min_size)
		if (-1 == addchar(' ', info->min_size - (size[0] + size[1]) -
					(info->flag_metadata * 2)))
			return (-1);
	return (1);
}

int					parse_p(t_info *info, va_list args)
{
	unsigned long long	d;
	char				*str;
	int					size[2];

	info->flag_metadata = 1;
	d = get_data(info->lenght_modifs, args);
	str = ft_itoa_base(d, "0123456789abcdef");
	size[1] = 0;
	if (info->precision != -1 || info->flag_minus)
	{
		if (!trt_one(info, str, size) || !trt_two(info, d, &str, size))
			return (-1);
	}
	else
	{
		if (-1 == treatment_without_zero_begining(info, &size[1], &str))
			return (-1);
		if (-1 == addchars(str, ft_strlen(str)))
			return (-1);
	}
	free(str);
	return (0);
}
