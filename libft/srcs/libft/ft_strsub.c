/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 23:04:55 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/05 16:04:45 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	result = (char*)malloc(sizeof(*result) * (len + 1));
	if (!result || s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < start)
		i++;
	while (s[i] != '\0' && (i - start) < len)
	{
		result[i - start] = s[i];
		i++;
	}
	result[i - start] = '\0';
	return (result);
}
