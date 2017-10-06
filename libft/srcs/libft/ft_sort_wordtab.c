/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:52:49 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/08 13:51:12 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sort(int counter, char **tab, int (*cmp)(const char *,
															const char *))
{
	char	*temp;
	int		i_1;
	int		i_2;

	i_1 = 0;
	i_2 = 0;
	while (i_1 < counter)
	{
		while (i_2 < counter)
		{
			if (cmp(tab[i_1], tab[i_2]) < 0)
			{
				temp = tab[i_1];
				tab[i_1] = tab[i_2];
				tab[i_2] = temp;
			}
			i_2++;
		}
		i_2 = 0;
		i_1++;
	}
}

void		ft_sort_wordtab(char **tab, int (*cmp)(const char *,
															const char *))
{
	int i;

	i = 0;
	while (tab[i] != 0)
		i++;
	sort(i, tab, cmp);
}
