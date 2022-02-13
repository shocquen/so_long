/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:51:03 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 16:22:24 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Outputs the integer ’n’ to the given file
	descriptor.
*/

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	unsigned int	i;
	char			buffer[11];

	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	i = 11;
	while (nbr || i == 11)
	{
		buffer[--i] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		buffer[--i] = '-';
	return (write(fd, buffer + i, 11 - i));
}
