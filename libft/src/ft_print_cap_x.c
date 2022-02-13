/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cap_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:40:12 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 12:34:43 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Print a number in hexa and return the size of it */

int	ft_print_cap_x(va_list args)
{
	size_t	nbr;
	size_t	size;

	nbr = va_arg(args, size_t);
	ft_putnbr_base((unsigned int)nbr, "0123456789ABCDEF");
	size = ft_lennb_unsigned((unsigned int)nbr, 16);
	return (size);
}
