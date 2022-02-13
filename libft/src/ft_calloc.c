/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:28:09 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/23 08:34:30 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	dest = (void *)malloc(count * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, count * size);
	return (dest);
}
