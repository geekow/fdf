/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 23:01:31 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/19 17:14:51 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t	len_dest;

	len_dest = ft_strlen(dest);
	if (count <= len_dest)
		return (ft_strlen(src) + count);
	if (count == (len_dest + 1))
		return (len_dest + ft_strlen(src));
	ft_strncat(dest, src, (count - len_dest - 1));
	return (len_dest + ft_strlen(src));
}
