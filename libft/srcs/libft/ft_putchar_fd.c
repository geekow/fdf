/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:56:41 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/10 07:24:25 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(unsigned int c, int fd)
{
	char	r[4];
	size_t	index;

	index = 0;
	if ((r[0] = (char)c) && c > 65535)
	{
		r[index++] = 240 | ((c >> 18));
		r[index++] = 128 | ((c >> 12) & 63);
		r[index++] = 128 | ((c >> 6) & 63);
		r[index] = 128 | (c & 63);
	}
	else if (c > 2047)
	{
		r[index++] = 224 | (c >> 12);
		r[index++] = 128 | ((c >> 6) & 63);
		r[index] = 128 | (c & 63);
	}
	else if (c > 127)
	{
		r[index++] = 192 | (c >> 6);
		r[index] = 128 | (c & 63);
	}
	write(fd, &r, ++index);
}
