/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:59:02 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/26 14:02:58 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Allocates (with malloc(3)) and returns an array
	of strings obtained by splitting ’s’ using the
	character ’c’ as a delimiter.  The array must be
	ended by a NULL pointer.
*/

static int	get_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
			++i;
		while (*s && *s != c)
			++s;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		count;
	int		cursor;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	count = get_size(s, c);
	ret = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ret)
		return (NULL);
	ret[count] = 0;
	i = 0;
	j = 0;
	while (i < count)
	{
		while (s[j] && s[j] == c)
			j++;
		cursor = j;
		while (s[j] && s[j] != c)
			j++;
		ret[i++] = ft_substr(s, cursor, j - cursor);
	}
	return (ret);
}
