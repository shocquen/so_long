#include "so_long.h"

static void	*ft_load_img(void **mlx, char *filename)
{
	int	a;
	int	b;

	return (mlx_xpm_file_to_image(*mlx, filename, &a, &b));
}

t_assets	*init_assets(void **mlx)
{
	t_assets *assets;
	assets = (t_assets *)malloc(sizeof(*assets) * 5);
	if (!assets)
		return (ft_error(CRED"Error: init_assets()\n"CNO));
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
	return (assets);
}

t_player	*init_player()
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(*player));
	if (!player)
		return (NULL);
	player->state = 0;
	player->mouves = 0;
	player->objects_count = 0;
	player->pos.x = 0;
	player->pos.y = 0;
	return (player);
}

t_map			*init_map(char *path)
{
	t_map	*map;
	char	*ret;

	if (!check_map_name(path))
		return (ft_error("Error: map path\n"));
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (ft_error("Error: malloc map\n"));
	map->collects_count = 0;
	map->map = NULL;
	int	fd;
	fd = open(path, O_RDONLY);
	if (!fd)
		return (ft_error("Error: map ain't open\n"));
	ret = get_next_line(fd);
	while (ret)
	{
		if (ret[(int)ft_strlen(ret) - 1] == '\n')
			ret[(int)ft_strlen(ret) - 1] = 0;
		ft_lstadd_back(&map->map, ft_lstnew(ret));
		ret = get_next_line(fd);
	}
	free(ret);
	if (!check_map_size(map->map))
		return(ft_error(CRED"Error: map's rows isn't the same size\n"CNO));
	map->height = ft_lstsize(map->map);
	map->width = ft_strlen(map->map->content);
	return (map);
}

void			init_window(t_game **game)
{
	(*game)->window = mlx_new_window((*game)->mlx,
			(*game)->map->width * 64,
			(*game)->map->height * 64,
			"so_long");
}