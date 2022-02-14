/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 00:58:08 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/14 01:37:39 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_list **map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[(int)ft_strlen(line) - 1] == '\n')
			line[(int)ft_strlen(line) - 1] = 0;
		ft_lstadd_back(map, ft_lstnew(line));
		line = get_next_line(fd);
	}
	free(line);
}

static int	apply_player(t_player **player, int x, int y)
{
	if ((*player)->state++)
		return (0);
	(*player)->pos.x = x;
	(*player)->pos.y = y;
	return (1);
}

void	*translate_map(t_game **game, char *line, int i, int j)
{
	int	k;

	k = -1;
	while (++k < 5)
	{
		if (line[j] == 'P' && !k)
			if (!apply_player(&((*game)->player), j, i))
				return (ft_error(CRED"Error: more than one player\n"CNO));
		if (line[j] == 'P' && !k)
			(*game)->map->collects_count++;
		if ((*game)->assets[k].key == line[j])
			ft_put_img((*game), j, i, k);
	}
	return (line);
}
