/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 20:46:19 by jjacobi           #+#    #+#             */
/*   Updated: 2016/12/05 17:16:29 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

# define BUFF_SIZE 420

typedef	struct	s_data
{
	int			fd;
	char		*content;
	char		end;
}				t_data;

int				get_next_line(const int fd, char **line);

#endif
