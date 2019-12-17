/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:09:08 by mkravetz          #+#    #+#             */
/*   Updated: 2019/12/17 16:25:23 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char **s1, char const *s2)
{
	char	*joined;
	int		len_s1;
	int		x;

	if (*s1 == NULL && s2 == NULL)
		return (NULL);
	if (*s1 == NULL)
	{
		free(*s1);
		return (ft_strdup(s2));
	}
	len_s1 = ft_strlen(*s1);
	x = ft_strlen(s2);
	if (!(joined = (char *)malloc(sizeof(char) * (len_s1 + x + 1))))
		return (NULL);
	x = -1;
	ft_memmove(joined, *s1, len_s1);
	x = -1;
	while (s2 && s2[++x])
		joined[len_s1 + x] = s2[x];
	joined[len_s1 + x] = '\0';
	free(*s1);
	return (joined);
}

char	*ft_strdup(const char *s1)
{
	int		x;
	char	*dest;

	dest = NULL;
	x = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[x])
	{
		dest[x] = s1[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t x;

	if (!s)
		return (0);
	x = 0;
	while (*s++)
		x++;
	return (x);
}
