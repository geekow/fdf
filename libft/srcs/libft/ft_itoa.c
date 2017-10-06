/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:53:22 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/26 19:14:41 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(long long n)
{
	size_t	result;

	result = 2;
	if (n >= 0)
	{
		result--;
		n = -n;
	}
	while (n < -9)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

char			*ft_itoa(long long n)
{
	char	*result;
	size_t	i;

	i = get_size(n);
	result = (char*)malloc(sizeof(*result) * (i + 1));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	else
		n = -n;
	result[i--] = '\0';
	while (n < -9)
	{
		result[i--] = -1 * (n % 10) + '0';
		n = n / 10;
	}
	result[i] = -1 * (n % 10) + '0';
	return (result);
}
