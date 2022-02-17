/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:10:06 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/17 11:30:09 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_row_wall(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1')
			return (1);
	}
	return (0);
}

static int	check_col_row(char *line)
{
	int	i;

	if (line[0] != '1')
		return (1);
	if (line[ft_strlen(line) - 1] != '1')
		return (1);
	i = -1;
	while (line[++i])
		if (line[i] != '0' && line[i] != '1' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
			return (1);
	return (0);
}

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
		{
			len = ft_strlen((char *)lst->content);
			if (check_row_wall((char *)lst->content))
				return (0);
		}
		else
			if (len != ft_strlen((char *)lst->content))
				return (0);
		if (check_col_row((char *)lst->content))
			return (0);
		if (!lst->next && check_row_wall((char *)lst->content))
			return (0);
		++i;
		lst = lst->next;
	}
	return (1);
}

/* Check if the extension of the map is .ber */

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
