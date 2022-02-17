/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 00:58:08 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/17 14:49:33 by shocquen         ###   ########.fr       */
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

static int	add_player(t_player **player, int x, int y)
{
	if ((*player)->state++)
		return (0);
	(*player)->pos.x = x;
	(*player)->pos.y = y;
	return (1);
}

static int	add_collect(t_list **lst, int x, int y)
{
	t_collect	*new;

	new = (t_collect *)malloc(sizeof(*new));
	if (!new)
		return (1);
	new->pos.x = x;
	new->pos.y = y;
	new->state = 1;
	ft_lstadd_back(lst, ft_lstnew(new));
	return (0);
}

void	*translate_map(t_game **game, char *line, int i, int j)
{
	int	k;

	k = -1;
	while (++k < 5)
	{
		if (line[j] == 'P' && !k)
			if (!add_player(&((*game)->player), j, i))
				return (ft_error(CRED"Error: more than one player\n"CNO));
		if (line[j] == 'C' && !k)
			if (add_collect(&(*game)->map->collects, j, i))
				return (ft_error(CRED"Error: collect wasn't added\n"CNO));
		if ((*game)->assets[k].key == line[j])
			ft_put_img((*game), j, i, k);
	}
	(*game)->map->collect_count = ft_lstsize((*game)->map->collects);
	return (line);
}

// TODO  collects is now a linked list, push to player when taking it;