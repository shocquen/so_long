/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:22:26 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 16:22:56 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Outputs the string ’s’ to the given file
	descriptor.
*/

int	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return (0);
	return (write(fd, s, ft_strlen(s)));
}
