/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:49:17 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/03 23:30:38 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	result_table(char charact)
{
	if ('0' <= charact && charact <= '9')
		return (1);
	else if (charact == '-')
		return (-1);
	else if (charact == '+')
		return (3);
	else if (charact == '\r' || charact == '\n' || charact == ' ' ||
			charact == '\t' || charact == '\v' || charact == '\f')
		return (2);
	else if (charact == '\0')
		return (-2);
	else
		return (0);
}

int			ft_atoi(const char *nptr)
{
	int index;
	int multiplicator;
	int condition;
	int result;

	condition = result_table(nptr[0]);
	index = 0;
	multiplicator = 1;
	result = 0;
	while (condition == 2)
	{
		condition = result_table(nptr[++index]);
	}
	if (condition == -1 || condition == 3)
	{
		if (condition == -1)
			multiplicator = -1;
		condition = result_table(nptr[++index]);
	}
	while (condition == 1)
	{
		result = result * 10 + (nptr[index] - '0');
		condition = result_table(nptr[++index]);
	}
	return (multiplicator * result);
}
