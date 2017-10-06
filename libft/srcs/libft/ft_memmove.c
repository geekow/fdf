/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:56:02 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/03 22:56:04 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*wdst;
	const char	*wsrc;

	wdst = dest;
	wsrc = src;
	if (wdst < wsrc)
		while (n)
		{
			*wdst++ = *wsrc++;
			n--;
		}
	else
	{
		wsrc += n;
		wdst += n;
		while (n)
		{
			*--wdst = *--wsrc;
			n--;
		}
	}
	return (dest);
}
