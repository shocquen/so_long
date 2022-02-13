/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:46:21 by shocquen          #+#    #+#             */
/*   Updated: 2022/02/08 19:42:46 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Add the element ’new’ at the beginning of the
	list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new->next = *lst;
	*lst = new;
}
