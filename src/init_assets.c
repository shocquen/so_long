/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:59:00 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/19 15:04:47 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_load_img(void **mlx, char *filename)
{
	int	a;
	int	b;

	return (mlx_xpm_file_to_image(*mlx, filename, &a, &b));
}

static void	*error_assets(t_assets **assets)
{
	free(*assets);
	return (ft_error(CRED"Error: init_assets(): load img\n"CNO));
}

t_assets	*init_assets(void **mlx)
{
	t_assets	*assets;
	int			i;

	assets = (t_assets *)malloc(sizeof(*assets) * 5);
	if (!assets)
		return (ft_error(CRED"Error: init_assets(): malloc\n"CNO));
	assets[0].img = ft_load_img(mlx, "img/player.xpm");
	assets[0].key = 'P';
	assets[1].img = ft_load_img(mlx, "img/wall.xpm");
	assets[1].key = '1';
	assets[2].img = ft_load_img(mlx, "img/log.xpm");
	assets[2].key = '0';
	assets[3].img = ft_load_img(mlx, "img/exit.xpm");
	assets[3].key = 'E';
	assets[4].img = ft_load_img(mlx, "img/collec.xpm");
	assets[4].key = 'C';
	i = -1;
	while (++i <= 4)
		if (!assets[i].img)
			return (error_assets(&assets));
	return (assets);
}
