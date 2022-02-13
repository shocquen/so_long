/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:30:58 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/26 10:35:32 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of the null-terminated string needle
** in the string haystack, where not more than len characters are searched.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	csr;
	size_t	i;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	csr = 0;
	i = 0;
	while (*haystack && *(haystack + csr) && csr < len)
	{
		if (*(haystack + csr) == *needle)
		{
			while ((*(haystack + csr + i) == *(needle + i)) && (csr + i) < len)
			{
				++i;
				if (!*(needle + i))
					return ((char *)(haystack + csr));
			}
		}
		csr++;
	}
	return (NULL);
}
