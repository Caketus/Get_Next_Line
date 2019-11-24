/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 22:08:41 by mkravetz          #+#    #+#             */
/*   Updated: 2019/11/24 22:32:38 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#define FILE "test1.txt"
int main()
{
	int fd;
	char *line;
	int line_count = 1;
	if ((fd = open("maxlenul.txt", O_RDONLY)) == -1)
	{
		printf("Couldn't open test file :(\n");
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		printf("Line %i: '%s'\n", line_count, line);
		line_count++;
	}
}
