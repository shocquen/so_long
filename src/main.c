/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:44:25 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/14 01:48:51 by shocquen         ###   ########.fr       */
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
		return (ft_error(CRED"Error: init_game(): assets\n"CNO));
	game->player = init_player();
	game->map = init_map(path);
	if (!game->map || !game->player)
	{
		free(game);
		return (ft_error(CRED"Error: init_game()\n"CNO));
	}
	init_window(&game);
	if (!game->window)
		return (ft_error(CRED"Error: mlx_new_window()\n"CNO));
	if (!apply_map(game))
		return (ft_error(CRED"Error: init_game()\n"CNO));
	return (game);
}

/* End the loop when pressing cross button */
int	end_game(t_game **game)
{
	mlx_loop_end((*game)->mlx);
	return (0);
}

/* Free all mallocs of the game */
int	free_game(t_game **game)
{
	int	i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image((*game)->mlx, (*game)->assets[i].img);
	free((*game)->assets);
	free((*game)->player);
	ft_lstclear(&(*game)->map->map, free);
	free((*game)->map);
	if ((*game)->window)
		mlx_destroy_window((*game)->mlx, (*game)->window);
	free((*game)->mlx);
	free(*game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (1);
	game = init_game(argv[1]);
	if (!game)
		exit (1);
	ft_printf("player: \n\tstate: %d\n\tpos: {x: %d, y: %d}\n",
		game->player->state, game->player->pos.x, game->player->pos.y);
	mlx_key_hook(game->window, key_hook, &game);
	mlx_hook(game->window, 17, 1, &end_game, &game);
	mlx_loop(game->mlx);
	free_game(&game);
}
