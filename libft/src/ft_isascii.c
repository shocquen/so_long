/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:30:31 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/25 15:48:11 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Tests for an ASCII character, which is any
** character between 0 and octal 0177 inclusive
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
