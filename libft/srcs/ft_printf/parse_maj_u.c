/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maj_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:42:50 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/27 16:33:01 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf/parse_info.h"

int	parse_maj_u(t_info *info, va_list args)
{
	info->lenght_modifs[0] = 'l';
	info->lenght_modifs[1] = '\0';
	return (parse_u(info, args));
}
