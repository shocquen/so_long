#include "so_long.h"

char	get_char(t_game *game, int x, int y)
{
	int		i;
	t_list	*tmp;


	tmp = game->map->map;
	i = 0;
	while (tmp)
	{
		if (i == y)
			return (((char *)tmp->content)[x]);
		/* while (((char *)tmp->content)[++j])
		{
			if (i == y && j == x)
				return (((char *)tmp->content)[j]);
		} */
		++i;
		tmp = tmp->next;
	}
	return (0);
}

/* 
	char c = get_type(t_game *game, int direction);
	if (c == 'E')
		move(t_game **game, int direction);
	else if (c == 'C')
	else if (c == 'E')
*/