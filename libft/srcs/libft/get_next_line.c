/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:35:13 by jjacobi           #+#    #+#             */
/*   Updated: 2016/12/05 20:22:04 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_lstremovecontent(t_list **list, int fd)
{
	t_list	*current;
	t_list	*previous;
	t_data	*data;

	previous = NULL;
	current = *list;
	while (current != NULL)
	{
		data = (t_data*)current->content;
		if (data->fd == fd)
		{
			if (previous == NULL)
				*list = current->next;
			else
				previous->next = current->next;
			free(data->content);
			free(data);
			free(current);
			return (0);
		}
		previous = current;
		current = current->next;
	}
	return (0);
}

static int	extend_content(t_data *data)
{
	int		i;
	char	*str;
	char	*result;

	i = 0;
	str = ft_strnew(BUFF_SIZE);
	if ((i = read(data->fd, str, BUFF_SIZE)) == -1)
		return (-1);
	if (data->content)
		result = ft_strjoin(data->content, str);
	else
		result = ft_strdup(str);
	free(data->content);
	free(str);
	data->content = result;
	if (i == 0 && !ft_strchr(data->content, '\n'))
		return (0);
	else
		return (1);
}

static int	parse(t_list **list, t_data *data, char **line)
{
	char	*str;
	int		i;

	while (1)
	{
		if (data->content && (str = ft_strchr(data->content, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(data->content);
			ft_memmove(data->content, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		if ((i = extend_content(data)) == -1)
			return (-1);
		else if (i == 0)
		{
			if (data->end || data->content[0] == '\0')
				return (ft_lstremovecontent(list, data->fd));
			*line = ft_strdup(data->content);
			data->end = 1;
			return (1);
		}
	}
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*cache;
	t_data			*data;

	cache = list;
	while (cache)
	{
		data = (t_data*)cache->content;
		if (data->fd == fd && line)
			return (parse(&list, data, line));
		cache = cache->next;
	}
	if (!(data = (t_data*)malloc(sizeof(t_data))) || !line)
		return (-1);
	data->fd = fd;
	data->content = NULL;
	data->end = 0;
	cache = ft_lstnew((void*)data, sizeof(t_data));
	free(data);
	if (list)
		ft_lstadd(&list, cache);
	else
		list = cache;
	return (get_next_line(fd, line));
}
