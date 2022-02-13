/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:44:50 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/30 10:46:50 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a substring
** from the string ’s’.
** The substring begins at index ’start’ and is of
** maximum size ’len’.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = (char *)malloc(sizeof(*s) * (len + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
