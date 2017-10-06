/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:04:04 by jjacobi           #+#    #+#             */
/*   Updated: 2017/02/01 20:13:56 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	valid_str(const char *str, int reset)
{
	static int	i = 1;

	if (reset)
	{
		i = 1;
		return (1);
	}
	if (i == 0)
		return (0);
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_strchr("sSpdDioOuUxXcC%", str[i]))
			return (1);
		i++;
	}
	i = 0;
	return (0);
}

static int	add_last_info(const char *format, size_t last_w, size_t i)
{
	if (valid_str("%s", 0))
	{
		if (-1 == addchars(&format[last_w], i - last_w))
			return (-1);
	}
	else
	{
		if (-1 == addchars(&format[last_w], ft_strchr(&format[last_w], '%')
					- &format[last_w]))
			return (-1);
	}
	return (1);
}

static int	check_not_valid(const char *format, size_t *i,
		size_t *last_w, t_info *info)
{
	if (format[*i] == '%' && !valid_str(format + *i, 0))
	{
		if (*i > *last_w && -1 == addchars(&format[*last_w], *i - *last_w))
			return (-1);
		info = stock(format + ++(*i), i);
		if (format[*i] && -1 == parse_noconv(info, format[(*i)++]))
			return (-1);
		if (-1 == addchars(&format[*i], ft_strlen(&format[*i])))
			return (-1);
		*last_w = *i;
		free(info);
	}
	return (1);
}

static int	save_last_pos_and_free(size_t i, t_info *info)
{
	free(info);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	last_w;
	size_t	i;
	t_info	*info;

	i = 0;
	last_w = 0;
	va_start(args, format);
	while (format[i])
	{
		if (check_not_valid(format, &i, &last_w, info) == -1)
			return (-1);
		while (format[i] == '%' && valid_str(format + i, 0))
		{
			if (i > last_w && -1 == addchars(&format[last_w], i - last_w))
				return (-1);
			if (!(info = stock(format + ++i, &i)) || -1 == parse(info, args))
				return (-1);
			last_w = save_last_pos_and_free(i, info);
		}
		i = (format[i]) ? i + 1 : i;
	}
	va_end(args);
	return (add_last_info(format, last_w, i) == -1
			|| !valid_str("", 1) ? -1 : write_or_stock_all(NULL, 0, 1, 1));
}
