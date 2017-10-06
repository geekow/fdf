/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:58:58 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/03 22:59:03 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i_src;
	size_t	i_dest;
	size_t	i;

	i_src = 0;
	i_dest = 0;
	i = 0;
	while (src[i_src] != '\0')
		i_src++;
	while (dest[i_dest] != '\0')
		i_dest++;
	while (i <= i_src)
	{
		dest[i_dest + i] = src[i];
		i++;
	}
	return (dest);
}
