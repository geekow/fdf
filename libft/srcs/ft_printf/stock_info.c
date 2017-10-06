/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:07:29 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/31 08:29:31 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static t_info	*create_info_struct(void)
{
	t_info		*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	info->argx = -1;
	info->flag_metadata = 0;
	info->flag_zero = 0;
	info->flag_minus = 0;
	info->flag_plus = 0;
	info->flag_space = 0;
	info->min_size = -1;
	info->precision = -1;
	info->lenght_modifs[0] = '\0';
	info->lenght_modifs[1] = '\0';
	info->conv_char = '\0';
	return (info);
}

static int		m_atoi(const char *nptr, size_t *size)
{
	int index;
	int result;

	index = 0;
	result = 0;
	while ('0' <= nptr[index] && nptr[index] <= '9')
		result = result * 10 + (nptr[index++] - '0');
	*size += index;
	return (result);
}

static int		stock_flag(const char c, t_info *info)
{
	size_t	i;

	i = 0;
	if (c == '0' && ++i)
		info->flag_zero = 1;
	else if (c == '#' && ++i)
		info->flag_metadata = 1;
	else if (c == '-' && ++i)
		info->flag_minus = 1;
	else if (c == '+' && ++i)
		info->flag_plus = 1;
	else if (c == ' ' && ++i)
		info->flag_space = 1;
	return (i);
}

static	int		stock_converter(const char *str, t_info *info)
{
	size_t	i;

	i = 0;
	if (str[i] == '.' && ++i)
		info->precision = m_atoi(&str[i], &i);
	if (str[i] && ft_strchr("hljz", str[i]))
	{
		info->lenght_modifs[0] = str[i++];
		if (str[i] == 'h' || str[i] == 'l')
		{
			if (ft_strchr("hl", info->lenght_modifs[0]))
				info->lenght_modifs[1] = str[i++];
			else
				i++;
		}
	}
	return (i);
}

t_info			*stock(const char *str, size_t *index)
{
	t_info		*info;
	int			tmp;
	size_t		i;

	if (!(info = create_info_struct()) || !str[0])
		return (NULL);
	i = 0;
	while (str[i] && !info->conv_char)
	{
		while (stock_flag(str[i], info) || str[i] == '$')
			i++;
		if (str[i] && ft_isdigit(str[i]) && ((tmp = m_atoi(&str[i], &i)) >= 0))
		{
			if (str[i] == '$' && i++)
				info->argx = tmp;
			else
				info->min_size = tmp;
		}
		i += stock_converter(&str[i], info);
		if ((!str[i] || !ft_strchr(VALIDCHAR, str[i])) && (*index += i))
			return (info);
		info->conv_char = ft_strchr("sSpdDioOuUxXcC%", str[i]) ? str[i] : '\0';
	}
	*index += i + 1;
	return (info);
}
