/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:44:25 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/19 14:41:54 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(char	*path)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(*game));
	if (!game)
		return (ft_error(CRED"Error: malloc t_game *game\n"CNO));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error(CRED"Error: mlx_init()\n"CNO));
	game->assets = init_assets(&(game->mlx));
	if (!game->assets)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game);
		return (ft_error(CRED"Error: init_game()\n"CNO));
	}
	game->player = init_player();
	game->map = init_map(path);
	if (!game->map || !game->player)
		return (ft_error(CRED"Error: init_game()\n"CNO));
	init_window(&game);
	if (!game->window)
		return (ft_error(CRED"Error: mlx_new_window()\n"CNO));
	if (!apply_map(game))
		return (ft_error(CRED"Error: init_game()\n"CNO));
	return (game);
}

static int check_exit(t_list *map)
{
	while (map)
	{
		if (ft_strchr((const char *)map->content, 'E'))
			return (1);
		map = map->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (1);
	if (!check_map_name(argv[1]))
	{
		ft_error(CRED"Error: map path\n"CNO);
		return (1);
	}
	game = init_game(argv[1]);
	if (!game)
	{
		return (1);
	}
	if (game->player->state && game->map->collect_count &&
		check_exit(game->map->map))
	{
		mlx_key_hook(game->window, key_hook, &game);
		mlx_hook(game->window, 17, 1, &end_game, &game);
		mlx_loop(game->mlx);
	}
	else
		ft_error(CRED"Error: seems like the map isn't perfect\n"CNO);
	free_game(&game);
}
