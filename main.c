/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 22:08:41 by mkravetz          #+#    #+#             */
/*   Updated: 2019/11/25 15:19:01 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int		main()
{
	char	*line;
	int		nb_line;
	int		fd;

	nb_line = 0;
	if ((fd = open("maxlenul.txt", O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");

	while (get_next_line(fd, &line) > 0)
	{
		printf("line is : [%d] %s\n", nb_line, line);
		nb_line++;
	}
}
