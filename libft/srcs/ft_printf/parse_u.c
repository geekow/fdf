/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:42:18 by jjacobi           #+#    #+#             */
/*   Updated: 2017/02/01 14:55:37 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	get_data(char modifs[2], va_list args)
{
	if (modifs[0] == '\0')
		return ((unsigned int)va_arg(args, unsigned int));
	else if (modifs[0] == 'h' && modifs[1] == 'h')
		return ((unsigned char)(va_arg(args, unsigned int)));
	else if (modifs[0] == 'h' && modifs[1] == '\0')
		return ((unsigned short)va_arg(args, unsigned int));
	else if (modifs[0] == 'l' && modifs[1] == '\0')
		return ((unsigned long)va_arg(args, unsigned long));
	else if (modifs[0] == 'l' && modifs[1] == 'l')
		return ((unsigned long long)va_arg(args, unsigned long long));
	else if (modifs[0] == 'j' && modifs[1] == '\0')
		return ((uintmax_t)va_arg(args, uintmax_t));
	else if (modifs[0] == 'z' && modifs[1] == '\0')
		return ((size_t)va_arg(args, size_t));
	else
		return ((unsigned int)va_arg(args, unsigned int));
}

static int			treatment_without_zero_begining(t_info *info, char **str)
{
	if (info->min_size > ((int)ft_strlen(*str))
		&& !info->flag_zero)
	{
		if (-1 == addchar(' ', info->min_size - ft_strlen(*str)))
			return (-1);
	}
	else if (info->min_size > ((int)ft_strlen(*str))
			&& info->flag_zero)
	{
		if (-1 == addchar('0', info->min_size - ft_strlen(*str)))
			return (-1);
	}
	return (1);
}

static int			trt_one(t_info *info, char *str,
											int *size)
{
	size[1] = 0;
	if ((int)ft_strlen(str) < info->precision)
		size[0] = info->precision;
	else
		size[0] = ft_strlen(str);
	if (size[0] < info->min_size && !info->flag_minus)
		if (!addchar(' ', info->min_size - size[0] - size[1]))
			return (-1);
	return (1);
}

static int			trt_two(t_info *info, unsigned long long d,
													char **str, int *size)
{
	if (info->precision >= 0)
	{
		if (-1 == addchar('0', size[0] - ft_strlen(*str)))
			return (-1);
	}
	if (info->precision == 0 && d == 0 && info->min_size != -1)
	{
		if (addchar(' ', 1) == -1)
			return (-1);
	}
	else if (info->precision != 0 || d != 0)
		if (-1 == addchars(*str, ft_strlen(*str)))
			return (-1);
	if (info->flag_minus && (size[0] + size[1]) < info->min_size)
		if (-1 == addchar(' ', info->min_size - (size[0] + size[1])))
			return (-1);
	return (1);
}

int					parse_u(t_info *info, va_list args)
{
	unsigned long long	d;
	char				*str;
	int					size[2];

	d = get_data(info->lenght_modifs, args);
	str = unsigned_itoa(d);
	if (info->precision != -1 || info->flag_minus)
	{
		if (!trt_one(info, str, size) || !trt_two(info, d, &str, size))
			return (-1);
	}
	else
	{
		if (-1 == treatment_without_zero_begining(info, &str))
			return (-1);
		if (-1 == addchars(str, ft_strlen(str)))
			return (-1);
	}
	free(str);
	return (0);
}
