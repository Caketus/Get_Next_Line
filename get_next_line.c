/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:19:55 by mkravetz          #+#    #+#             */
/*   Updated: 2019/11/24 22:44:43 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t x;

	x = 0;
	while (*s++)
		x++;
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		len_s1;
	int		x;

	if (s1 == NULL || s2 == NULL)
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

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		temp[BUFFER_SIZE + 1];
	static char	*rest;
	int			i;
	int			j;
	char		buff[BUFFER_SIZE + 1];

	i = 0;
	j = 0;
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
			rest = malloc(sizeof(char) * (BUFFER_SIZE + 1) - i);
			while (buff[i])
			{
				rest[j] = buff[i];
				i++;
				j++;
			}
			*line = ft_strjoin(*line, temp);
			printf("char line == %s\n", *line);
			printf("temp == %s\n", temp);
			printf("rest == %s\n", rest);
			return (1);
		}
		else
		{
			*line = ft_strjoin(*line, temp);
		}
	}
	return (ret);
}
