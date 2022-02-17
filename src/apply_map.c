/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 01:05:22 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/17 11:33:59 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(t_game *game, int x, int y, int asset)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->assets[asset].img,
		x * 64, y * 64);
}

void	*apply_map(t_game *game)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = game->map->map;
	i = 0;
	while (tmp)
	{
		j = -1;
		while (((char *)tmp->content)[++j])
			if (!translate_map(&game, ((char *)tmp->content), i, j))
				return (ft_error(CRED"Error: apply_map()\n"CNO));
		++i;
		tmp = tmp->next;
	}
	return (game);
}
