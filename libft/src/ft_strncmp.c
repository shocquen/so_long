/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:30:55 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/29 15:14:28 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* compares not more than n characters. */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (n);
	while ((*s1 || *s2) && (*s1 == *s2) && --n)
	{
		++s1;
		++s2;
	}
	return (((unsigned char) *s1) - ((unsigned char) *s2));
}
