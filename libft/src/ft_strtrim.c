/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:38:31 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/29 11:54:53 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* 
	Allocates (with malloc(3)) and returns a copy of
	’s1’ with the characters specified in ’set’ removed
	from the beginning and the end of the string.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	return (ft_substr((char *)s1, 0, len + 1));
}
