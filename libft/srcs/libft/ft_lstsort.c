/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:12:06 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/07 19:37:13 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **begin_list, int (*cmp)(char *a, char *b))
{
	t_list	*list;
	t_list	*cache;
	void	*data;
	size_t	tmp;

	list = *begin_list;
	if (list)
		while (list->next != 0)
		{
			cache = list;
			while (cache)
			{
				if (cmp((char*)list->content, (char*)cache->content) < 0)
				{
					data = list->content;
					tmp = list->content_size;
					list->content = cache->content;
					list->content_size = cache->content_size;
					cache->content = data;
					cache->content_size = tmp;
				}
				cache = cache->next;
			}
			list = list->next;
		}
}
