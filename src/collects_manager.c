/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collects_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:40:29 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/19 13:47:49 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_collect	*del_collect(t_collect *old, int x, int y)
{
	t_collect	*new;

	new = (t_collect *)malloc(sizeof(*new));
	if (!new)
		return (ft_error(CRED"Error: del_collect()\n"CNO));
	if (old->pos.x == x && old->pos.y == y)
	{
		new->pos.x = x;
		new->pos.y = y;
		new->state = 0;
	}
	else
	{		
		new->pos.x = old->pos.x;
		new->pos.y = old->pos.y;
		new->state = old->state;
	}
	return (new);
}

t_list	*col_map(t_list *lst, void (*del)(void *), int x, int y)
{
	t_list	*new_lst;
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	tmp = NULL;
	while (lst)
	{
		new = ft_lstnew(del_collect(lst->content, x, y));
		if (!new)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new);
		tmp = lst->next;
		ft_lstdelone(lst, free);
		lst = tmp;
	}
	return (new_lst);
}

void	collect_map(t_list **lst, void (*del)(void *), int x, int y)
{
	t_list	*tmp;
	t_list	*new_lst;
	t_list	*new;

	if (!lst)
		return ;
	new_lst = NULL;
	tmp = *lst;
	while (tmp)
	{
		new = ft_lstnew(del_collect(tmp->content, x, y));
		if (!new)
		{
			ft_lstclear(&new_lst, del);
			return ;
		}
		ft_lstadd_back(&new_lst, new);
		tmp = tmp->next;
	}
	ft_lstclear(lst, free);
	lst = &new_lst;
}

int	count_col(t_list *lst)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (lst)
	{
		if (!((t_collect *)lst->content)->state)
			i++;
		y++;
		lst = lst->next;
	}
	if (i == y)
		return (-1);
	return (i);
}
