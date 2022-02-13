/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:30:21 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/25 16:04:21 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Writes n zeroed bytes to the string s. */

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
