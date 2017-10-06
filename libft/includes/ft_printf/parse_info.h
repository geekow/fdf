/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:06:05 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/11 06:21:03 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INFO_H
# define PARSE_INFO_H

int				parse_s(t_info *info, va_list args);
int				parse_maj_s(t_info *info, va_list args);
int				parse_p(t_info *info, va_list args);
int				parse_d(t_info *info, va_list args);
int				parse_maj_d(t_info *info, va_list args);
int				parse_i(t_info *info, va_list args);
int				parse_o(t_info *info, va_list args);
int				parse_maj_o(t_info *info, va_list args);
int				parse_u(t_info *info, va_list args);
int				parse_maj_u(t_info *info, va_list args);
int				parse_x(t_info *info, va_list args);
int				parse_maj_x(t_info *info, va_list args);
int				parse_c(t_info *info, va_list args);
int				parse_maj_c(t_info *info, va_list args);
int				parse_percent(t_info *info, va_list args);

#endif
