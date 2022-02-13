/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:42:25 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/25 16:15:38 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Returns a pointer to the first occurrence
	of the character c in the string s.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		++s;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
