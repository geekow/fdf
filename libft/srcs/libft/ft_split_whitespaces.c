/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:36:46 by jjacobi           #+#    #+#             */
/*   Updated: 2016/11/19 16:57:34 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_tab_size(char const *s)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		while (s[i] == 32 || (9 <= s[i] && s[i] <= 13))
			i++;
		if (s[i] == '\0')
			return (result);
		while (s[i] != '\0' && !(s[i] == 32 || (9 <= s[i] && s[i] <= 13)))
			i++;
		result += 1;
	}
	return (result);
}

static char		*str_to_put(char const *s, size_t *i)
{
	char	*result;
	size_t	j;
	size_t	k;

	while (s[*i] != '\0' && (s[*i] == 32 || (9 <= s[*i] && s[*i] <= 13)))
		*i += 1;
	j = *i;
	k = j;
	while (s[*i] != '\0' && !(s[*i] == 32 || (9 <= s[*i] && s[*i] <= 13)))
		*i += 1;
	if ((result = (char*)malloc(sizeof(*result) * (*i - j))) == NULL)
		return (NULL);
	while (j < *i)
	{
		result[j - k] = s[j];
		j++;
	}
	result[j - k] = '\0';
	return (result);
}

char			**ft_split_whitespaces(char *str)
{
	char	**result;
	size_t	w;
	size_t	w_max;
	size_t	i;

	if (str == NULL)
		return (NULL);
	w_max = get_tab_size(str);
	if ((result = (char**)malloc(sizeof(*result) * (w_max + 1))) == NULL)
		return (NULL);
	w = 0;
	i = 0;
	while (w < w_max)
		if ((result[w++] = str_to_put(str, &i)) == NULL)
			return (NULL);
	result[w] = 0;
	return (result);
}
