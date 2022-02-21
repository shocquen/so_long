/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:59:00 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/21 11:29:01 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_load_img(void **mlx, char *filename)
{
	int	a;
	int	b;

	return (mlx_xpm_file_to_image(*mlx, filename, &a, &b));
}

static void	*error_assets(t_assets **assets, void **mlx, int top)
{
	int	i;

	i = -1;
	while (++i < top)
	{
		if ((*assets)[i].img)
		{
			ft_printf("test: %d/%d\n", i, top - 1);
			mlx_destroy_image((*mlx), (*assets)[i].img);
		}
	}
	free(*assets);
	return (ft_error(CRED"Error: init_assets(): load img\n"CNO));
}

static t_assets	set_asset(void **mlx, char key, char *path)
{
	t_assets	ret;

	ret.img = ft_load_img(mlx, path);
	ret.key = key;
	return (ret);
}

t_assets	*init_assets(void **mlx)
{
	t_assets	*assets;
	int			i;

	assets = (t_assets *)malloc(sizeof(*assets) * 5);
	if (!assets)
		return (ft_error(CRED"Error: init_assets(): malloc\n"CNO));
	i = -1;
	assets[++i] = set_asset(mlx, 'P', PLAYER_PATH);
	if (!assets[i].img)
		return (error_assets(&assets, mlx, i));
	assets[++i] = set_asset(mlx, '1', WALL_PATH);
	if (!assets[i].img)
		return (error_assets(&assets, mlx, i));
	assets[++i] = set_asset(mlx, '0', EMPTY_PATH);
	if (!assets[i].img)
		return (error_assets(&assets, mlx, i));
	assets[++i] = set_asset(mlx, 'E', EXIT_PATH);
	if (!assets[i].img)
		return (error_assets(&assets, mlx, i));
	assets[++i] = set_asset(mlx, 'C', COLLECT_PATH);
	if (!assets[i].img)
		return (error_assets(&assets, mlx, i));
	return (assets);
}
