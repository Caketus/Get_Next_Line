/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:09:08 by mkravetz          #+#    #+#             */
/*   Updated: 2019/12/10 21:49:05 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			x;
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;

	if (dst == 0 && src == 0)
		return (0);
	ptrdst = (unsigned char*)dst;
	ptrsrc = (unsigned char*)src;
	x = -1;
	if (ptrdst < ptrsrc)
		while (++x < len)
			ptrdst[x] = ptrsrc[x];
	else
		while (len-- > 0)
			ptrdst[len] = ptrsrc[len];
	return (dst);
}
