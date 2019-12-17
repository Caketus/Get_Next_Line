/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:47:15 by mkravetz          #+#    #+#             */
/*   Updated: 2019/12/17 19:47:53 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char **s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
#endif
