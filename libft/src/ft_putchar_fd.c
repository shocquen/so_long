/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:14:34 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 16:22:06 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Outputs the character ’c’ to the given file
	descriptor.
*/

int	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (0);
	return (write(fd, &c, 1));
}
