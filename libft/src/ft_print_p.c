/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:04:02 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 12:35:57 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Print a void * arg in Hexa and return how may char printed */

int	ft_print_p(va_list args)
{
	size_t	nbr;

	nbr = va_arg(args, size_t);
	if (nbr == 0)
		return (ft_putstr_fd("0x0", 1));
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(nbr, "0123456789abcdef");
	return (ft_lennb_unsigned(nbr, 16) + 2);
}
