/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 22:08:41 by mkravetz          #+#    #+#             */
/*   Updated: 2019/12/13 14:29:19 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int		main(void)
{
	char	*line;
	int		nb_line;
	int		fd;

	nb_line = 1;
	if ((fd = open("maxlenul.txt", O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");
	line = NULL;
	while (get_next_line(fd, &line) > 0 && nb_line)
	{
		printf("line[%d]: %s\n", nb_line, line);
		free(line);
		line = NULL;
		nb_line++;
	}
	free(line);
//	system("leaks a.out");
}
