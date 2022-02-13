/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:52:16 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 12:34:42 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Print decimal number and return nbr's size */

int	ft_print_di(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	return (ft_putnbr_fd(nbr, 1));
}
