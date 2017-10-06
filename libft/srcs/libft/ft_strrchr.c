/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 23:04:15 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/03 23:18:09 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
		{
			ptr = (char*)s + i;
			return (ptr);
		}
		i--;
	}
	if (s[i] == (char)c)
	{
		ptr = (char*)s + i;
		return (ptr);
	}
	return (NULL);
}
