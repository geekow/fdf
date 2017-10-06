/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:42:23 by jjacobi           #+#    #+#             */
/*   Updated: 2017/02/01 17:46:09 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	get_data(char modifs[2], va_list args)
{
	if (modifs[0] == '\0')
		return ((long long)va_arg(args, int));
	else if (modifs[0] == 'h' && modifs[1] == 'h')
		return ((signed char)(va_arg(args, int)));
	else if (modifs[0] == 'h' && modifs[1] == '\0')
		return ((short)va_arg(args, int));
	else if (modifs[0] == 'l' && modifs[1] == '\0')
		return ((long)va_arg(args, long));
	else if (modifs[0] == 'l' && modifs[1] == 'l')
		return ((long long)va_arg(args, long long));
	else if (modifs[0] == 'j' && modifs[1] == '\0')
		return ((intmax_t)va_arg(args, intmax_t));
	else if (modifs[0] == 'z' && modifs[1] == '\0')
		return ((size_t)va_arg(args, size_t));
	else
		return ((int)va_arg(args, int));
}

static int			treatment_without_zero_begining(t_info *info, int *special,
														char **str, long long d)
{
	if (!(*special = 0) && (info->flag_plus || info->flag_space) && d >= 0)
		*special = *special + 1;
	if (info->min_size > (*special + (int)ft_strlen(*str))
		&& !info->flag_zero)
	{
		if (-1 == addchar(' ', info->min_size - *special - ft_strlen(*str)))
			return (-1);
	}
	else if (info->min_size >= (*special + (int)ft_strlen(*str))
			&& info->flag_zero)
	{
		if (info->flag_plus && d >= 0)
		{
			if (-1 == addchar('+', 1))
				return (-1);
		}
		else if (d < 0 && (*str = *str + 1) && (*special += 1))
		{
			if (-1 == addchar('-', 1))
				return (-1);
		}
		if (-1 == addchar('0', info->min_size - *special - ft_strlen(*str)))
			return (-1);
	}
	return (1);
}

static int			trt_one(t_info *info, char *str,
													int *size, long long d)
{
	size[1] = 0;
	if ((int)ft_strlen(str) < info->precision)
		size[0] = info->precision;
	else
		size[0] = ft_strlen(str);
	if ((info->flag_plus || info->flag_space) && d >= 0)
		size[1] = size[1] + 1;
	if (d < 0 && info->precision >= 0 && info->precision == size[0])
		size[1] = size[1] + 1;
	if (size[0] < info->min_size && !info->flag_minus)
		if (!addchar(' ', info->min_size - size[0] - size[1]))
			return (0);
	if (info->flag_space && d >= 0 && !info->flag_plus)
		if (-1 == addchar(' ', 1))
			return (0);
	if (info->flag_plus && d >= 0)
		if (-1 == addchar('+', 1))
			return (0);
	return (1);
}

static int			trt_two(t_info *info, int d,
													char **str, int *size)
{
	if (info->precision >= 0)
	{
		if (d < 0 && (*str = *str + 1))
		{
			if (size[0] != info->precision)
				size[0] = size[0] - 1;
			if (addchar('-', 1) == -1 ||
					addchar('0', size[0] - ft_strlen(*str)) == -1)
				return (0);
		}
		else if (-1 == addchar('0', size[0] - ft_strlen(*str)))
			return (0);
	}
	if (info->precision == 0 && d == 0 && info->min_size != -1)
	{
		if (addchar(' ', 1) == -1)
			return (0);
	}
	else if (info->precision != 0 || d != 0)
		if (-1 == addchars(*str, ft_strlen(*str)))
			return (0);
	if (info->flag_minus && (size[0] + size[1]) < info->min_size)
		if (-1 == addchar(' ', info->min_size - (size[0] + size[1])))
			return (0);
	return (1);
}

int					parse_d(t_info *info, va_list args)
{
	long long	d;
	char		*str;
	int			size[2];

	d = get_data(info->lenght_modifs, args);
	if ((str = ft_itoa(d)) && (info->precision != -1 || info->flag_minus))
	{
		if (!trt_one(info, str, size, d) || !trt_two(info, d, &str, size))
			return (-1);
	}
	else
	{
		if (info->flag_space && d >= 0 && !info->flag_plus)
			if (-1 == addchar(' ', 1))
				return (-1);
		if (-1 == treatment_without_zero_begining(info, &size[1], &str, d))
			return (-1);
		if (info->flag_plus && d >= 0 && (!info->flag_zero ||
info->min_size < (size[1] + (int)ft_strlen(str))) && -1 == addchar('+', 1))
			return (-1);
		if (-1 == addchars(str, ft_strlen(str)))
			return (-1);
	}
	(d < 0 && str[0] != '-') ? free(--str) : free(str);
	return (0);
}
