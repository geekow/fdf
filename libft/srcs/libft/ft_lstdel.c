/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:06:05 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/07 11:08:38 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cache;

	while (*alst)
	{
		if (del)
			del((*alst)->content, (*alst)->content_size);
		cache = (*alst)->next;
		free(*alst);
		(*alst) = cache;
	}
	*alst = NULL;
}
