/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:10:06 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/13 23:11:30 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if each lines of the map is the same size */
int	check_map_size(t_list *lst)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (lst)
	{
		if (i == 0)
			len = ft_strlen((char *)lst->content);
		else
			if (len != ft_strlen((char *)lst->content))
				return (0);
		++i;
		lst = lst->next;
	}
	return (1);
}

/* Check if the extension of the map is .ber */
#define EXTENSION ".ber"

int	check_map_name(char *name)
{
	int	len;
	int	i;

	if (*name == '.')
		return (0);
	len = (int)ft_strlen(name);
	i = 0;
	while (++i <= 4)
	{
		if (name[len - i] != EXTENSION[4 - i])
			return (0);
	}
	return (1);
}
