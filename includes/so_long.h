/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:44:31 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/15 16:05:26 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

/* Colors */
# define CRED "\033[0;31m"
# define CGRN "\033[0;32m"
# define CYLW "\033[0;33m"
# define CNO "\033[0;39m"

/* keycodes */
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

/* Postition of an entity */
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

/* The player */
typedef struct s_player
{
	int				state;
	int				mouves;
	int				collects_count;
	t_pos			pos;
}	t_player;

/* Collectible */
typedef struct s_collect
{
	t_pos			pos;
	int				state;
}	t_collect;

/* The map */
typedef struct s_map
{
	int				width;
	int				height;
	int				collects_count;
	t_list			*map;
	t_collect		*collects;
}	t_map;

/* Assets of the game*/
# define PLAYER 0
# define WALL 1
# define EMPTY 2
# define EXIT 3
# define COLLECT 4

typedef struct s_assets
{
	void	*img;
	char	key;
}	t_assets;

/* The game */
typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_assets		*assets;
	t_player		*player;
	t_map			*map;
}	t_game;

int				end_game(t_game **game);

/* Init */
void			init_window(t_game **game);
t_map			*init_map(char *path);
t_player		*init_player(void);
t_assets		*init_assets(void **mlx);

/* map_checks */
int				check_map_size(t_list *lst);
int				check_map_name(char	*name);

/* Print */
void			*ft_error(const char *msg);

/* Moves */
char			get_char(t_game *game, int x, int y);

/* Hooks */
int				key_hook(int keycode, t_game **game);

/* Apply map */
void			ft_put_img(t_game *game, int x, int y, int asset);
void			*apply_map(t_game *game);
void			*translate_map(t_game **game, char *line, int i, int j);

/* Utils */
void			read_map(t_list **map, int fd);

#endif
