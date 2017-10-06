/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 23:02:44 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/03 23:16:21 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		result;

	result = 0;
	index = 0;
	if (n == 0)
		return (0);
	while (s1[index] == s2[index] && index < n)
	{
		if (s1[index] == '\0')
			return (0);
		index++;
	}
	if (index == n)
		return (0);
	result = (unsigned char)s1[index] - (unsigned char)s2[index];
	return (result);
}
