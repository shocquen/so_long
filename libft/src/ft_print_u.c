/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:36:38 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 12:34:39 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Print unsigned decimal nb and return how many bytes printed */

int	ft_print_u(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	ft_putnbr_base(nb, "0123456789");
	return (ft_lennb_unsigned(nb, 10));
}
