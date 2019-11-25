/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:20:20 by mkravetz          #+#    #+#             */
/*   Updated: 2019/11/25 14:43:27 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_check(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
#endif
