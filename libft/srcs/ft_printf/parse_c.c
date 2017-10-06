/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:41:12 by jjacobi           #+#    #+#             */
/*   Updated: 2017/02/02 01:43:14 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <wchar.h>

static int	flag_zero(char flag_minus, char flag_zero, int min_size, int size)
{
	if (!flag_minus && flag_zero && ((min_size - size) > 0))
		return (addchar('0', min_size - size));
	return (1);
}

static int	flag_space(char flag_minus, char flag_zero, int min_size, int size)
{
	if (!flag_minus && !flag_zero && ((min_size - size) > 0))
		return (addchar(' ', min_size - size));
	return (1);
}

static int	calc_unicode_size(wint_t *wc, unsigned char *c,
											va_list args, t_info *info)
{
	if (info->lenght_modifs[0] == 'l' && info->lenght_modifs[1] == '\0')
	{
		*wc = (wint_t)va_arg(args, wint_t);
		if (*wc > 65535)
			return (4);
		else if (*wc > 2047)
			return (3);
		else if (*wc > 127)
			return (2);
		else
			return (1);
	}
	else
	{
		*c = (unsigned char)va_arg(args, int);
		return (1);
	}
}

int			parse_c(t_info *info, va_list args)
{
	unsigned char	c;
	wint_t			wc;
	int				size;

	size = calc_unicode_size(&wc, &c, args, info);
	if (!flag_zero(info->flag_minus, info->flag_zero, info->min_size, size))
		return (-1);
	if (!flag_space(info->flag_minus, info->flag_zero, info->min_size, size))
		return (-1);
	if (info->lenght_modifs[0] == 'l' && info->lenght_modifs[1] == '\0')
	{
		if (wc > 1114111 || !addunicode((int)wc))
			return (-1);
	}
	else
	{
		if (!addchar(c, 1))
			return (-1);
	}
	if (info->flag_minus && (info->min_size > size))
		if (!flag_space(0, 0, info->min_size, size))
			return (-1);
	return (1);
}
