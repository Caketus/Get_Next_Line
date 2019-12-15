/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:37:00 by mkravetz          #+#    #+#             */
/*   Updated: 2019/12/15 20:50:08 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		ft_check(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == c)
			return (1);
	}
	return (0);
}

static int		error(char **rest, int ret)
{
	if (*rest)
	{
		free(rest);
		rest = 0;
	}
	return (ret);
}

static int		ret_rest(char *rest, char **line, char *temp)
{
	int		i;

	if (rest && *rest)
	{
		if (ft_check(rest, '\n') == 0)
		{
			if (!(*line = ft_strjoin(line, rest)))
				return (error(&rest, -1));
			rest = NULL;
		}
		else
		{
			i = -1;
			while (rest[++i] != '\n' && rest[i])
				temp[i] = rest[i];
			temp[i] = '\0';
			if (!(*line = ft_strjoin(line, temp)))
				return (error(&rest, -1));
			ft_memmove(rest, &rest[i + 1], ft_strlen(rest) - i);
			return (1);
		}
	}
	return (0);
}

/*
**Free rest to prevent leaks in the strdup line 83
*/

static int		has_newline(char **rest, char **line, char *temp, char *buff)
{
	int		i;

	if (ft_check(buff, '\n') == 1)
	{
		i = -1;
		while (buff[++i] != '\n')
			temp[i] = buff[i];
		temp[i] = '\0';
		if (!(*line = ft_strjoin(line, temp)))
			return (error(rest, -1));
		free(*rest);
		*rest = NULL;
		if (!(*rest = ft_strdup(&buff[i + 1])))
			return (error(rest, -1));
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	char		temp[BUFFER_SIZE + 1];
	static char	*rest[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];

	if (!line || (fd < 0 || fd >= OPEN_MAX) || (read(fd, buff, 0) < 0)
			|| BUFFER_SIZE < 1)
		return (error(&rest[fd], -1));
	*line = ft_strdup("");
	if (ret_rest(rest[fd], line, temp) == 1)
		return (1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (has_newline(&rest[fd], line, temp, buff) == 1)
			return (1);
		if (!(*line = ft_strjoin(line, buff)))
			return (error(&rest[fd], -1));
	}
	return (ret);
}
