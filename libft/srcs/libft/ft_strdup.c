/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 23:00:14 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/03 23:00:18 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dest = (char*)malloc(sizeof(char) * ++i);
	if (!dest)
		return (NULL);
	while (i-- > 0)
	{
		dest[i] = s[i];
	}
	return (dest);
}
