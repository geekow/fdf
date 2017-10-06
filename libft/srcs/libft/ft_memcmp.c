/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:54:55 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/03 23:10:46 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*w1;
	unsigned char	*w2;
	size_t			i;

	w1 = (unsigned char *)s1;
	w2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (w1[i] != w2[i])
			return ((int)(w1[i] - w2[i]));
		i++;
	}
	return (0);
}
