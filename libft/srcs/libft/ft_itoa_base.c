/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:10:53 by jjacobi           #+#    #+#             */
/*   Updated: 2017/01/28 00:43:09 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long long value, char *base)
{
	int						size;
	unsigned long long		tmp;
	int						base_size;
	char					*result;

	tmp = value;
	base_size = ft_strlen(base);
	size = 1;
	if (base_size < 2)
		return (NULL);
	while ((tmp / base_size) > 0)
	{
		tmp = tmp / base_size;
		size++;
	}
	result = (char*)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	while ((value / base_size) > 0)
	{
		result[--size] = base[value % base_size];
		value = value / base_size;
	}
	result[0] = base[value % base_size];
	return (result);
}
