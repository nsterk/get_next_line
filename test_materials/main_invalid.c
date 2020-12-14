/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_invalid.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 19:22:37 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/13 15:26:50 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 10
// #endif

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int				main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	i = 1;
	fd = 43;
	ret = get_next_line(fd, &line);
	if (ret == -1)
		printf("you return -1 when given 43 as fd, yay\n");
	else
		printf("you don't return -1 when given 42 as fd :(\n");
	fd = -1;
	ret = get_next_line(fd, &line);
	if (ret == -1)
		printf("you return -1 when given -1 as fd, yay\n");
	else
		printf("you don't return -1 when given -1 as fd :(\n");
	fd = open("main.c", O_RDONLY);
	if (fd < 0)
	{
		printf("failed to open file\n");
		return (0);
	}
	ret = get_next_line(fd, NULL);
	if (ret == -1)
		printf("you return -1 when given NULL as argument for line, yay\n");
	else
		printf("you don't return -1 when NULL as argument for line :(\n");
	return (0);
}
