/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_maj_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 01:41:44 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/29 14:38:39 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf/parse_info.h"

int	parse_maj_s(t_info *info, va_list args)
{
	info->lenght_modifs[0] = 'l';
	info->lenght_modifs[1] = '\0';
	return (parse_s(info, args));
}
