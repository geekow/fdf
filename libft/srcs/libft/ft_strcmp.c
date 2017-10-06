/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:59:36 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/03 23:11:48 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;
	int		result;

	index = 0;
	while (s1[index] == s2[index])
		if (s1[index++] == '\0')
			return (0);
	result = (unsigned char)s1[index] - (unsigned char)s2[index];
	return (result);
}
