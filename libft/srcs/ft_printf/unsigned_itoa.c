/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:18:48 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/27 15:26:02 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(unsigned long long n)
{
	size_t	result;

	result = 1;
	while (n > 9)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

char			*unsigned_itoa(unsigned long long n)
{
	char	*result;
	size_t	i;

	i = get_size(n);
	result = (char*)malloc(sizeof(*result) * (i + 1));
	if (!result)
		return (NULL);
	result[i--] = '\0';
	while (n > 9)
	{
		result[i--] = (n % 10) + '0';
		n = n / 10;
	}
	result[i] = (n % 10) + '0';
	return (result);
}
