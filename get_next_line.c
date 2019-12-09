/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:19:55 by mkravetz          #+#    #+#             */
/*   Updated: 2019/12/09 20:22:11 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strdup(const char *s1)
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

static int		ft_check(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (1);
	return (0);
}

static size_t	ft_strlen(const char *s)
{
	size_t x;

	x = 0;
	while (*s++)
		x++;
	return (x);
}

static char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		len_s1;
	int		x;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	x = ft_strlen(s2);
	if (!(joined = (char *)malloc(sizeof(char) * (len_s1 + x + 1))))
		return (NULL);
	x = -1;
	while (s1[++x])
		joined[x] = s1[x];
	x = -1;
	while (s2[++x])
		joined[len_s1 + x] = s2[x];
	joined[len_s1 + x] = '\0';
	return (joined);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	char		temp[BUFFER_SIZE + 1];
	static char	rest[BUFFER_SIZE + 1];
	int			i;
	int			j;
	char		buff[BUFFER_SIZE + 1];

	i = 0;
	j = 0;
	if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(*line) + 1))))
		return (0);
	*line = "";
	if (*rest)
	{
		*line = ft_strjoin(rest, *line);
	}
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_check(buff, '\n') == 1)
		{
			while (buff[i] != '\n')
			{
				temp[i] = buff[i];
				i++;
			}
			temp[i] = '\0';
			while (buff[i])
			{
				rest[j] = buff[i + 1];
				i++;
				j++;
			}
			*line = ft_strjoin(*line, temp);
			return (1);
		}
		else
		{
			*line = ft_strjoin(*line, buff);
		}
	}
	return (ret);
}
