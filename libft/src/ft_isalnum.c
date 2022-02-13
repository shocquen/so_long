/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:30:24 by shocquen          #+#    #+#             */
/*   Updated: 2021/08/05 10:01:03 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Return 1 if c is alphanum */

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
