/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:47:29 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 12:36:24 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Print a string and return len(str) or 0 */

int	ft_print_s(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		return (ft_putstr_fd("(null)", 1));
	}	
	if (str)
		return (ft_putstr_fd(str, 1));
	return (0);
}
