/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:34:16 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/07 19:34:39 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int nb, int power)
{
	int counter;
	int final_value;

	final_value = 1;
	counter = 0;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (counter < power)
	{
		final_value = final_value * nb;
		counter++;
	}
	return (final_value);
}
