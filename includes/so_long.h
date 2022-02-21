/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:44:31 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/21 11:15:12 by shocquen         ###   ########.fr       */
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

/* Assets of the game*/
# define PLAYER 0
# define WALL 1
# define EMPTY 2
# define EXIT 3
# define COLLECT 4

/* Assets path */
# define PLAYER_PATH "img/player.xpm"
# define WALL_PATH "img/wall.xpm"
# define EMPTY_PATH "img/log.xpm"
# define EXIT_PATH "img/exit.xpm"
# define COLLECT_PATH "img/collec.xpm"

/* map_check */
# define EXTENSION ".ber"

// * Structs
/* Postition of an entity */
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_player
{
	int				state;
	int				mouves;
	t_pos			pos;
}	t_player;

typedef struct s_collect
{
	t_pos			pos;
	int				state;
}	t_collect;

typedef struct s_map
{
	int				width;
	int				height;
	int				collect_count;
	t_list			*collects;
	t_list			*map;
}	t_map;

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

/* end_game */
int				end_game(t_game **game);
int				free_game(t_game **game);

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

/* map_util */
void			read_map(t_list **map, int fd);

/* collect_manager */
void			collect_map(t_list **lst, void (*del)(void *), int x, int y);
int				count_col(t_list *lst);
t_list			*col_map(t_list *lst, void (*del)(void *), int x, int y);

#endif
