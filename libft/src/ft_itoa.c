/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:15:26 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/25 11:37:22 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Allocates (with malloc(3)) and returns a string
	representing the integer received as an argument.
	Negative numbers must be handled.
*/

static size_t	intlen(int n)
{
	size_t	count;

	if (n != 0)
		count = 0;
	else
		count = 1;
	while (n)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t			len;
	size_t			n_tmp;
	char			*str;

	if (n < 0)
		n_tmp = -(unsigned int)n;
	else
		n_tmp = n;
	if (n < 0)
		len = intlen(n_tmp) + 1;
	else
		len = intlen(n_tmp);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n_tmp % 10 + '0';
		n_tmp /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
