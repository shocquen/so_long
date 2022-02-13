/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:24:46 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 12:34:35 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putnbr_base(size_t nbr, const char *base)
{
	unsigned long long int	a;
	unsigned long long int	new_nbr;

	a = ft_strlen(base);
	new_nbr = (unsigned long long int)nbr;
	if (new_nbr >= a)
		ft_putnbr_base(new_nbr / a, base);
	ft_putchar_fd(base[new_nbr % a], 1);
}
