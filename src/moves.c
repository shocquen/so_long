/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 01:50:34 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/14 01:50:50 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		++i;
		tmp = tmp->next;
	}
	return (0);
}
