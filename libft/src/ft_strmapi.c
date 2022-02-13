/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:43:41 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/25 13:28:36 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Applies the function ’f’ to each character of
	the string ’s’ , and passing its index as first
	argument to create a new string (with malloc(3))
	resulting from successive applications of ’f’.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = 0;
	while (len--)
		ret[len] = (*f)(len, s[len]);
	return (ret);
}
