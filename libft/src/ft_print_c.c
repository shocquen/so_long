/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:45:11 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 12:34:44 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* Print a char and return 1 */

int	ft_print_c(va_list args)
{
	ft_putchar_fd((char)va_arg(args, int), 1);
	return (1);
}
