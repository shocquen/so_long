/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:10:58 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/25 16:13:13 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d_tmp;
	const unsigned char	*s_tmp;

	if (!dst && !src)
		return (NULL);
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		d_tmp = dst + len;
		s_tmp = src + len;
		while (len--)
			*--d_tmp = *--s_tmp;
	}
	return (dst);
}
