/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 01:49:52 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/14 01:50:26 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game **game, int x, int y)
{
	char	c;

	c = get_char(*game, x, y);
	if (c == 'E' && (*game)->map->collects_count)
		return ;
	ft_put_img(*game, (*game)->player->pos.x, (*game)->player->pos.y, EMPTY);
	(*game)->player->pos.x = x;
	(*game)->player->pos.y = y;
	ft_printf("mouves: "CYLW"%d\n"CNO, ++(*game)->player->mouves);
	ft_put_img(*game, (*game)->player->pos.x, (*game)->player->pos.y, PLAYER);
	if (c == 'C')
	{
		(*game)->player->objects_count++;
		(*game)->map->collects_count--;
	}
	if (c == 'E' && !(*game)->map->collects_count)
		end_game(game);
}

int	key_hook(int keycode, t_game **game)
{
	int		x;
	int		y;

	if (keycode == KEY_ESC)
		return (end_game(game));
	if (keycode != KEY_D
		&& keycode != KEY_W && keycode != KEY_S && keycode != KEY_A)
		return (1);
	x = (*game)->player->pos.x;
	y = (*game)->player->pos.y;
	if (keycode == KEY_W)
		y--;
	else if (keycode == KEY_S)
		y++;
	if (keycode == KEY_A)
		x--;
	else if (keycode == KEY_D)
		x++;
	if (get_char(*game, x, y) != '1')
		move_player(game, x, y);
	return (0);
}
