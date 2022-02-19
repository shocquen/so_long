/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:32:40 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/19 14:24:22 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if ((*game)->assets[i].img && (*game)->mlx)
			mlx_destroy_image((*game)->mlx, (*game)->assets[i].img);
	free((*game)->assets);
	free((*game)->player);
	ft_lstclear(&(*game)->map->map, free);
	ft_lstclear(&(*game)->map->collects, free);
	free((*game)->map);
	if ((*game)->window)
		mlx_destroy_window((*game)->mlx, (*game)->window);
	mlx_destroy_display((*game)->mlx);
	free((*game)->mlx);
	free(*game);
	return (0);
}
