/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:43:18 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/29 11:58:21 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Allocates (with malloc(3)) and returns a new
	element.  The variable ’content’ is initialized
	with the value of the parameter ’content’.  The
	variable ’next’ is initialized to NULL.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (ret)
	{
		ret->content = content;
		ret->next = NULL;
	}
	return (ret);
}
