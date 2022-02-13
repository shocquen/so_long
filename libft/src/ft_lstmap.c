/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:38:52 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/29 12:41:31 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Iterates the list ’lst’ and applies the function
	’f’ to the content of each element.  Creates a new
	list resulting of the successive applications of
	the function ’f’.  The ’del’ function is used to
	delete the content of an element if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new;

	if (!lst || !(f))
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new = ft_lstnew((f)(lst->content));
		if (!new)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new);
		lst = lst->next;
	}
	return (new_lst);
}
