/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:38:13 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/31 08:29:42 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf/parse_info.h"

void	initialize_parsing_ptr(int (*g_ptr[122]) (t_info *info, va_list args))
{
	g_ptr[115] = parse_s;
	g_ptr[83] = parse_maj_s;
	g_ptr[112] = parse_p;
	g_ptr[100] = parse_d;
	g_ptr[68] = parse_maj_d;
	g_ptr[105] = parse_i;
	g_ptr[111] = parse_o;
	g_ptr[79] = parse_maj_o;
	g_ptr[117] = parse_u;
	g_ptr[85] = parse_maj_u;
	g_ptr[120] = parse_x;
	g_ptr[88] = parse_maj_x;
	g_ptr[99] = parse_c;
	g_ptr[67] = parse_maj_c;
	g_ptr[37] = parse_percent;
}

int		parse(t_info *info, va_list args)
{
	static int	(*g_ptr[122]) (t_info *info, va_list args) = { NULL };

	if (g_ptr[115] == NULL)
		initialize_parsing_ptr(g_ptr);
	if (info->conv_char == '\0')
		return (1);
	return ((*g_ptr[(int)info->conv_char])(info, args));
}
