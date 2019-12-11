/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:19:55 by mkravetz          #+#    #+#             */
/*   Updated: 2019/12/11 23:29:13 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t x;

	x = 0;
	while (*s++)
		x++;
	return (x);
}

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
	static char	*rest;
	int			i;
	char		buff[BUFFER_SIZE + 1];

	if (!(*line = (char *)malloc(sizeof(char) * (ft_strlen(*line) + 1))))
		return (0);
	*line = "";
	if (rest && *rest)
	{
		printf("rest == %s\n", rest);
		//printf("\x1b[34m" "rest == %s\n" "\x1b[0m", rest);
		if (ft_check(rest, '\n') == 0) // pas de '\n'
		{
			*line = ft_strdup(rest);
			//*line = ft_strjoin(*line, rest);
			rest = NULL;
		}

		else
		{
			i = -1;
			while (rest[++i] != '\n')
			{
				temp[i] = rest[i];
				i++;
			}
			temp[i] = '\0';
			*line = ft_strjoin(*line, temp);
		//	printf("rest before memove == %s\n", rest);
			rest = ft_memmove(rest, &rest[i + 1], ft_strlen(rest) - i);
		//	printf("rest after memove == %s\n", rest);
		//	ft_memset(rest, 0, ft_strlen(rest));
			return (1);
		}
	}
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_check(buff, '\n') == 1)
		{
			i = -1;
			while (buff[++i] != '\n')
			{
				temp[i] = buff[i];
			}
			temp[i] = '\0';
			*line = ft_strjoin(*line, temp);
			rest = ft_strdup(&buff[i + 1]);
			return (1);
		}
		else
		{
			*line = ft_strjoin(*line, buff);
		}
	}
	return (ret);
}
