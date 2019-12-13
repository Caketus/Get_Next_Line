/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:19:55 by mkravetz          #+#    #+#             */
/*   Updated: 2019/12/13 21:04:49 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/*
** Double pointer just to be able to add \0
*/

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
			if (!(*line = ft_strdup(rest)))
				error(&rest, -1);
			rest = NULL;
		}
		else
		{
			i = -1;
			while (rest[++i] != '\n' && rest[i])
			{
				temp[i] = rest[i];
			}
			temp[i] = '\0';
			if (!(*line = ft_strjoin(*line, temp)))
				error(&rest, -1);
			ft_memmove(rest, &rest[i + 1], ft_strlen(rest) - i);
			return (1);
		}
	}
	return (0);
}

static int		has_newline(char *rest, char **line, char *temp, char *buff)
{
	int		i;
	
	if (ft_check(buff, '\n') == 1)
	{
		i = -1;
		while (buff[++i] != '\n')
			temp[i] = buff[i];
		temp[i + 1] = '\0';
		if (!(*line = ft_strdup(temp)))
			error(&rest, -1);
		if (!(rest = ft_strdup(&buff[i + 1])))
			error(&rest, -1);
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	char		temp[BUFFER_SIZE + 1];
	static char	*rest;
	char		buff[BUFFER_SIZE + 1];
	
//	if (!(line))
//	   return (-1);	
//	if (ret_rest(rest, line, temp) <= -1)
//		return (-1);
		int l;
		l = 0;
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		l++;
		buff[ret] = '\0';
		if (has_newline(rest, line, temp, buff) == 1)
			return (1);
		if (*line)
		{
			printf("coucou\n");
			*line = ft_strjoin(*line, buff);
		}
		if (!(*line))
			printf("qwdoinqwdiodnqw\n");	
		else 
			*line = ft_strdup(buff);
	}
	if (!(*line = ft_strjoin(*line, buff)))
		return (-1);
	return (ret);
}
