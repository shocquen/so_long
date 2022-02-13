/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lennb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:00:47 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 12:34:47 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_lennb(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		nb = -nb;
		i++;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_lennb_unsigned(unsigned long long int nb, int base)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}
