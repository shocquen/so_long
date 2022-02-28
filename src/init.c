/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 23:06:40 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/28 13:20:48 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(*player));
	if (!player)
		return (NULL);
	ft_memset(player, 0, sizeof(*player));
	return (player);
}

static void	*error_map(const char *msg, void *ptr)
{
	free(ptr);
	return (ft_error(msg));
}

t_map	*init_map(char *path)
{
	t_map	*map;
	int		fd;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (ft_error(CRED"Error: malloc map\n"CNO));
	map->collects = NULL;
	map->collect_count = 0;
	map->map = NULL;
	fd = open(path, O_RDONLY);
	if (!fd)
		return (ft_error(CRED"Error: map ain't open\n"CNO));
	read_map(&map->map, fd);
	if (!check_map_size(map->map) || !map->map)
		return (error_map(CRED"Error: map can't be parsed\n"CNO, map));
	map->height = ft_lstsize(map->map);
	map->width = ft_strlen(map->map->content);
	return (map);
}

void	init_window(t_game **game)
{
	(*game)->window = mlx_new_window((*game)->mlx,
			(*game)->map->width * 64,
			(*game)->map->height * 64,
			"so_long");
}
