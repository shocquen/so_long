#include "so_long.h"

void	ft_put_img(t_game *game, int x, int y, int asset)
{
	mlx_put_image_to_window(game->mlx, game->window,
			game->assets[asset].img,
			x * 64, y * 64);
}

static int	apply_player(t_player **player, int x, int y)
{
	if ((*player)->state++)
		return (0);
	(*player)->pos.x = x;
	(*player)->pos.y = y;
	return (1);
}

void				*apply_map(t_game *game, t_player **player)
{
	int		i;
	int		j;
	int		k;
	t_list	*tmp;

	tmp = game->map->map;
	i = 0;
	while (tmp)
	{
		j = -1;
		while (((char *)tmp->content)[++j])
		{
			k = -1;
			while (++k < 5)
			{
				if (((char *)tmp->content)[j] == 'P' && !k)
					if (!apply_player(player, j, i))
						return (ft_error(CRED"Error: more than one player\n"CNO));
				if (((char *)tmp->content)[j] == 'P' && !k)
					game->map->collects_count++;
				if (game->assets[k].key == ((char *)tmp->content)[j])
					ft_put_img(game, j, i, k);
			}
		}
		++i;
		tmp = tmp->next;
	}
	return (game);
}