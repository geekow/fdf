/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:54:35 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/03 23:10:17 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*w;
	size_t			i;

	w = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (w[i] == (unsigned char)c)
			return (&w[i]);
		i++;
	}
	return (NULL);
}
