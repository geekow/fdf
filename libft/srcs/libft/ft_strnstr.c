/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 23:03:34 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/05 18:41:31 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index_str;
	size_t	index_tf;
	int		tmp;

	index_str = 0;
	if (needle[0] == '\0' || haystack == needle)
		return ((char*)haystack);
	while (haystack[index_str] && len)
	{
		index_tf = 0;
		len--;
		while (haystack[index_str + index_tf] == needle[index_tf])
		{
			tmp = len - index_tf;
			if (tmp < 0)
				return ((char*)0);
			if (needle[++index_tf] == '\0')
				return ((char*)&haystack[index_str]);
		}
		index_str++;
	}
	return ((char*)0);
}
