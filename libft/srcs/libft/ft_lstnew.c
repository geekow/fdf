/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:07:15 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/07 12:40:29 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = ft_memalloc(content_size);
	if (list->content && content)
	{
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	else if (content == NULL && list->content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		free(list);
		return (NULL);
	}
	list->next = NULL;
	return (list);
}
