/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:16:30 by shocquen          #+#    #+#             */
/*   Updated: 2021/12/18 12:34:37 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle(t_handler *handler, va_list args, char ctx)
{
	int	i;

	i = -1;
	while (i++ < 9)
		if (handler[i].ctx == ctx)
			return (handler[i].f(args));
	return (0);
}

int	ft_parse(char ctx, va_list args)
{
	t_handler	handler[9];

	handler[0].f = &ft_print_c;
	handler[0].ctx = 'c';
	handler[1].f = &ft_print_s;
	handler[1].ctx = 's';
	handler[2].f = &ft_print_p;
	handler[2].ctx = 'p';
	handler[3].f = &ft_print_di;
	handler[3].ctx = 'd';
	handler[4].f = &ft_print_u;
	handler[4].ctx = 'u';
	handler[5].f = &ft_print_di;
	handler[5].ctx = 'i';
	handler[6].f = &ft_print_x;
	handler[6].ctx = 'x';
	handler[7].f = &ft_print_cap_x;
	handler[7].ctx = 'X';
	handler[8].f = &ft_print_percent;
	handler[8].ctx = '%';
	return (ft_handle(handler, args, ctx));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;
	int		i;

	va_start(args, str);
	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += ft_parse(str[++i], args);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i++], 1);
			ret++;
		}
	}
	return (ret);
}
